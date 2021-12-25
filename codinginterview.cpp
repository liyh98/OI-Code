#include <bits/stdc++.h>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	unsigned char x;
};

int count(Node *node)
{
	if (node == NULL)
		return 1;
	return 1 + count(node->left) + count(node->right);
}

unsigned char *serialize(Node node)
{
	int pos = 0;
	unsigned char *arr = new unsigned char[count(&node) * 2];
	stack<pair<Node *, bool>> st;
	st.emplace(&node, 0);
	while (!st.empty())
	{
		Node *node;
		bool state;
		tie(node, state) = st.top();
		st.pop();
		if (node == NULL)
			pos += 2;
		else if (!state)
		{
			arr[pos++] = 1;
			arr[pos++] = node->x;
			st.emplace(node, true);
			st.emplace(node->left, false);
		}
		else
			st.emplace(node->right, false);
	}
	return arr;
}

// basically when accepting the output from the serialize() function, it should regenerate a tree of the same structure

Node deserialize(unsigned char *bytes)
{
	Node *root;
	stack<pair<Node *, bool>> st;
	st.emplace(root, false);
	int pos = 0;
	while (!st.empty())
	{
		Node *node;
		bool state;
		tie(node, state) = st.top();
		st.pop();
		if (!state)
		{
			if (bytes[pos++] == 0)
			{
				node = NULL;
				++pos;
			}
			else
			{
				node = new Node();
				node->x = bytes[pos++];
				st.emplace(node, true);
				st.emplace(node->left, false);
			}
		}
		else
			st.emplace(node->right, false);
	}
	return *root;
}

int main()
{

	return 0;
}