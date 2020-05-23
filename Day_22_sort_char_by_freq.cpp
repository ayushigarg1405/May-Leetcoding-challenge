Question:

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Solution Approach:

Use unordered_map to store the freq of char.
Use priority queue to store max freq.
Keep adding the char to result;

Solution:

class Solution {
public:
    
    string frequencySort(string s) {
       
        unordered_map<char, int> m;
	for( auto c : s )
		++m[c];

	priority_queue<pair<int, char>> maxHeap;
	for( auto p : m )
		maxHeap.push( { p.second, p.first } );

	string result = "";
	while( !maxHeap.empty() ) {
		auto p = maxHeap.top(); maxHeap.pop();
		while( p.first-- )
			result += p.second;
	}
	return result;
    }
};
