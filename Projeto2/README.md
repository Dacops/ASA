**TODO: Figure out relation inbetween number of edges & weights.**
**Probable fix: first check graphs with 1 vertix taken then with 2.**

**Problem:** Giving a undirected graph find the heaviest path that connects all vertices.
**Solution:**
- **Part 1:** Sort the entries by weight, we can create a vector with n entries where each entries correspond to a weight. Then we read each edge and send each (u, v) edge to the correspondent 'w' bucket. There should be no negative or 0 edges, therefore index0 = weight1, index1 = weight2, ...
This part of the code has a complexity of:
$$O(n)$$

- **Part 2:** Read the sorted input, start removing the higher weight edges and mark which vertices were already reached. If a edge has at least a not marked vertice add it and mark that vertices.
This part of the code has a complexity of:
$$O(n)$$
