#include <iostream>

struct Storage {
  explicit Storage(size_t size) : size_(size), buffer_(new int[size_]) {
    std::cout << "Storage(size_t " << size_ << ")" << std::endl;
  }

  Storage& operator=(Storage& other) {
    size_ = other.size_;
    delete[] buffer_;
    buffer_ = new int[size_];
    for (size_t idx = 0; idx != size_; ++idx) {
      buffer_[idx] = other.buffer_[idx];
    }
    std::cout << "Storage& operator=(Storage& " << size_ << ")" << std::endl;
    return *this;
  }

  Storage& operator=(Storage&& other) {
    std::swap(other.size_, size_);
    std::swap(other.buffer_, buffer_);
    std::cout << "Storage& operator=(Storage&& " << size_ << ")" << std::endl;
    return *this;
  }

  Storage(Storage&& other) {
    std::swap(other.size_, size_);
    std::swap(other.buffer_, buffer_);
    std::cout << "Storage(Storage&& " << size_ << ")" << std::endl;
  }

  Storage operator+(Storage const& rha) {
    Storage result = Storage(this->size_ + rha.size_);
    for (size_t idx = 0; idx != this->size_; ++idx) {
      result.buffer_[idx] = this->buffer_[idx];
    }
    for (size_t idx = 0; idx != rha.size_; ++idx) {
      result.buffer_[this->size_ + idx] = rha.buffer_[idx];
    }
    std::cout << "Storage operator+(Storage const&)" << std::endl;
    return result;
  }

  ~Storage() {
    delete[] buffer_;
    std::cout << "~Storage(" << size_ << ")" << std::endl;
  }
  private:
    size_t size_ = 0;
    int* buffer_ = nullptr;
};

int main() {
  Storage storage0 = Storage(10);
  Storage storage1 = Storage(20);
  storage0 = storage1;
  storage0 = std::move(storage1);
  std::cout << std::endl;
  Storage storage3 = std::move(storage0 + storage1);
  Storage&& storage4 = storage0 + storage1;
  return 0;
}
