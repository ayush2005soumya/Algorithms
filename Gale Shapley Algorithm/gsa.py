def gale_shapley(men_prefs, women_prefs):
    n = len(men_prefs)
    free_men = list(men_prefs.keys())
    engaged = {}
    proposals = {man: [] for man in men_prefs}
    inv_women_prefs = {
        w: {man: rank for rank, man in enumerate(prefs)}
        for w, prefs in women_prefs.items()
    }

    while free_men:
        man = free_men.pop(0)
        man_pref = men_prefs[man]
        for woman in man_pref:
            if woman not in proposals[man]:
                proposals[man].append(woman)
                if woman not in engaged:
                    engaged[woman] = man
                    break
                else:
                    current = engaged[woman]
                    if inv_women_prefs[woman][man] < inv_women_prefs[woman][current]:
                        engaged[woman] = man
                        free_men.append(current)
                        break
    return {v: k for k, v in engaged.items()}  # man -> woman

# Example
men = {
    "A": ["X", "Y", "Z"],
    "B": ["Y", "X", "Z"],
    "C": ["Y", "Z", "X"]
}
women = {
    "X": ["B", "A", "C"],
    "Y": ["C", "A", "B"],
    "Z": ["A", "C", "B"]
}

matches = gale_shapley(men, women)
for man, woman in matches.items():
    print(f"{man} is matched with {woman}")
