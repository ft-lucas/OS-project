# OS-project
# Assignment Q1
A number of cats and mice inhabit a house. The cats and mice have worked out a deal
where the mice can steal pieces of the cats’ food, so long as the cats never see the mice
actually doing so. If the cats see the mice, then the cats must eat the mice (or else lose
face with all of their cat friends). There are NumBowls cat food dishes, NumCats cats,
and NumMice mice. Your job is to synchronize the cats and mice so that the following
requirements are satisfied:
No mouse should ever get eaten. You should assume that if a cat is eating at a food dish, any
mouse attempting to eat from that dish or any other food dish will be seen and eaten. When
cats aren’t eating, they will not see mice eating. In other words, this requirement states that if
a cat is eating from any bowl, then no mouse should be eating from any bowl. Only one
mouse or one cat may eat from a given dish at any one time. Neither cats nor mice should
starve. A cat or mouse that wants to eat should eventually be able to eat. For example, a
synchronization solution that permanently prevents all mice from eating would be
unacceptable. When we actually test your solution, each simulated cat and mouse will only
eat a finite number of times; however, even if the simulation were allowed to run forever,
neither cats nor mice should starve.