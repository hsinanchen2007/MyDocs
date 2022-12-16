namespace dss
{
inline DemoBinaryTree::~DemoBinaryTree()
{
  _destroyAllNodes();
}

inline bool DemoBinaryTree::empty() const
{
  return false;
}

inline DemoBinaryTree::size_type DemoBinaryTree::size() const
{
  return _n.size();
}

inline DemoBinaryTree::const_reference DemoBinaryTree::front() const
{
  return _head->element;
}

inline DemoBinaryTree::const_reference DemoBinaryTree::back() const
{
  return _tail->element;
}

inline DemoBinaryTree::key_compare DemoBinaryTree::key_comp() const
{
  return _predicate;
}

inline const DemoBinaryTree::Node* DemoBinaryTree::root() const
{
  return _root;
}

inline const DemoBinaryTree::Node* DemoBinaryTree::head() const
{
  return _head;
}

inline const DemoBinaryTree::Node* DemoBinaryTree::tail() const
{
  return _tail;
}

inline DemoBinaryTree::reference DemoBinaryTree::front()
{
  return _head->element;
}

inline DemoBinaryTree::reference DemoBinaryTree::back()
{
  return _tail->element;
}

DemoBinaryTree::Node* DemoBinaryTree::_createNode(
  const value_type& sourceElement)
{
  Node* newNode = _alloc.allocate(1);
  _alloc.construct(newNode, Node(sourceElement));

  return newNode;
}

void DemoBinaryTree::_createAllNodes()
{
  _n[0] = _createNode(value_type(0, 'A'));
  _n[1] = _createNode(value_type(3, 'B'));
  _n[2] = _createNode(value_type(6, 'C'));
  _n[3] = _createNode(value_type(9, 'D'));
  _n[4] = _createNode(value_type(12, 'E'));
  _n[5] = _createNode(value_type(15, 'F'));
  _n[6] = _createNode(value_type(18, 'G'));
  _n[7] = _createNode(value_type(21, 'H'));
  _n[8] = _createNode(value_type(24, 'I'));
  _n[9] = _createNode(value_type(27, 'J'));
  _n[10] = _createNode(value_type(30, 'K'));
  _n[11] = _createNode(value_type(33, 'L'));
  _n[12] = _createNode(value_type(36, 'M'));
  _n[13] = _createNode(value_type(39, 'N'));
  _n[14] = _createNode(value_type(42, 'O'));
}

void DemoBinaryTree::_setParentAndChildLinks()
{
  // level 0 (2^0 = 1 node)

  _n[7]->parent = nullptr;
  _n[7]->left = _n[3];
  _n[7]->right = _n[11];

  // level 1 (2^1 = 2 nodes)

  _n[3]->parent = _n[7];
  _n[3]->left = _n[1];
  _n[3]->right = _n[5];

  _n[11]->parent = _n[7];
  _n[11]->left = _n[9];
  _n[11]->right = _n[13];

  // level 2 (2^2 = 4 nodes)

  _n[1]->parent = _n[3];
  _n[1]->left = _n[0];
  _n[1]->right = _n[2];

  _n[5]->parent = _n[3];
  _n[5]->left = _n[4];
  _n[5]->right = _n[6];

  _n[9]->parent = _n[11];
  _n[9]->left = _n[8];
  _n[9]->right = _n[10];

  _n[13]->parent = _n[11];
  _n[13]->left = _n[12];
  _n[13]->right = _n[14];

  // level 3 (2^3 = 8 nodes)

  _n[0]->parent = _n[1];
  _n[0]->left = nullptr;
  _n[0]->right = nullptr;

  _n[2]->parent = _n[1];
  _n[2]->left = nullptr;
  _n[2]->right = nullptr;

  _n[4]->parent = _n[5];
  _n[4]->left = nullptr;
  _n[4]->right = nullptr;

  _n[6]->parent = _n[5];
  _n[6]->left = nullptr;
  _n[6]->right = nullptr;

  _n[8]->parent = _n[9];
  _n[8]->left = nullptr;
  _n[8]->right = nullptr;

  _n[10]->parent = _n[9];
  _n[10]->left = nullptr;
  _n[10]->right = nullptr;

  _n[12]->parent = _n[13];
  _n[12]->left = nullptr;
  _n[12]->right = nullptr;

  _n[14]->parent = _n[13];
  _n[14]->left = nullptr;
  _n[14]->right = nullptr;
}

inline void DemoBinaryTree::_destroyNode(Node* n)
{
  _alloc.destroy(n);
  _alloc.deallocate(n);
}
};

// For the book "C++ Data Structures from Scratch" (www.cppdatastructures.com)
// Copyright 2015 by Robert MacGregor.  All rights reserved.