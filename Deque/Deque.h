#ifndef __DEQUE_HEADER_INCLUDED__
#define __DEQUE_HEADER_INCLUDED__

class Deque {
 public:
  static const int INIT_CAPACITY = 20;

  Deque();
  Deque(const Deque&);
  Deque& operator=(const Deque&);
  ~Deque();

  int& front();
  int& back();
  void push_front(const int&);
  void push_back(const int&);
  void pop_front();
  void pop_back();
  int& at(int);
  int& operator[](int);
  int operator[](int) const;
  int size() const;
  int capacity() const;
  bool empty() const;
  void reserve(int);

 private:
  int m_capacity;
  int m_size;
  int m_head;
  int* m_data;

  void initialize();
  void copy(const Deque&);
  void clear();
};

Deque::Deque() {
  m_data = nullptr;
  initialize();
}

Deque::Deque(const Deque& other) {
  initialize();
  copy(other);
}

Deque& Deque::operator=(const Deque& other) {
  if (this != &other) {
    copy(other);
  }

  return *this;
}

Deque::~Deque() { clear(); }

int& Deque::front() { return at(0); }

int& Deque::back() { return at(m_size - 1); }

void Deque::push_front(const int& value) {
  if (m_size == m_capacity) {
    reserve(m_capacity * 2);
  }

  m_head = (m_head + m_capacity - 1) % m_capacity;
  m_data[m_head] = value;
  m_size++;
}

void Deque::push_back(const int& value) {
  if (m_size == m_capacity) {
    reserve(m_capacity * 2);
  }

  m_data[(m_head + m_size) % m_capacity] = value;
  m_size++;
}

void Deque::pop_front() {
  if (m_size <= 0) {
    throw "Invalid size value!";
  }

  m_head = (m_head + 1) % m_capacity;
  m_size--;
}

void Deque::pop_back() {
  if (m_size <= 0) {
    throw "Invalid size value!";
  }

  m_size--;
}

int& Deque::at(int index) {
  if (index < 0 && index >= m_size) {
    throw "Invalid index value!";
  }

  return m_data[(m_head + index) % m_capacity];
}

int& Deque::operator[](int index) {
  if (index < 0 || index >= (int)m_size) {
    throw "Invalid index value!";
  }

  return m_data[index];
}

int Deque::operator[](int index) const {
  if (index < 0 || index >= (int)m_size) {
    return 0;
  }

  return m_data[index];
}

int Deque::size() const { return m_size; }

int Deque::capacity() const { return m_capacity; }

bool Deque::empty() const { return !m_size; }

void Deque::reserve(int capacity) {
  int* temp = new int[capacity];
  for (size_t i = 0; i < m_size; ++i) {
    temp[i] = m_data[(m_head + i) % m_capacity];
  }

  delete[] m_data;
  m_head = 0;
  m_data = temp;
  m_capacity = capacity;
}

void Deque::initialize() {
  if (m_data != nullptr) {
    delete[] m_data;
  }

  m_head = 0;
  m_size = 0;
  m_capacity = INIT_CAPACITY;
  m_data = new int[m_capacity];
}

void Deque::copy(const Deque& other) {
  if (m_data != nullptr) {
    delete[] m_data;
  }

  m_capacity = other.m_capacity;
  m_data = new int[m_capacity];

  for (size_t i = 0; i < other.m_size; ++i) {
    m_data[i] = other.m_data[(other.m_head + i) % other.m_capacity];
  }

  m_size = other.m_size;
  m_head = 0;
}

void Deque::clear() { initialize(); }

#endif