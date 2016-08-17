#pragma once

#include <array>
#include <algorithm>

namespace mw {

/**
 * \brief Class for managing packets and their contents.
 * \details This class is used to manage packets and what
 * information they contain, allowing you to easily input
 * information into a packet and extract it.
 */
class Packet {
public:
    /**
     * \brief A maximum size for the packet.
     */
    static const size_t MAX_SIZE = 128;

    /**
     * \brief Initialize a packet setting everything to the
     * default variables.
     */
    Packet() {
        index_ = 0;
        size_ = 0;
    }

    /**
     * \brief Initialize a packet providing its contents.
     * \details Initialize the packet providing it with the
     * contents of the file and the size of said information
     * in terms of bytes.
     * @param[in] data The data to put in the packet.
     * @param[in] size The size in bytes of the data that was
     * input.
     */
    Packet(const char *data, int size) {
        index_ = 0;
        std::copy(data, data + size, data_.data());
        size_ = size;
    }

    /**
     * \brief Append packet data to the current packet
     * @param[in] packet Another packet to be appended to the
     * current one.
     * \warning Dangerous if the size of the packet is too big.
     */
    Packet &operator<<(const Packet &packet) {
        std::copy(packet.data_.data(), packet.data_.data() + packet.size_, data_.data() + size_);
        size_ += packet.size_;
        return *this;
    }

    /**
     * \brief Retrieve a byte from the packet.
     * @param[out] byte A byte to copy bytes from the packet to.
     */
    Packet &operator>>(char &byte) {
        byte = data_[index_++];
        return *this;
    }

    /**
     * \brief Append a byte to the packet.
     * @param[in] byte A byte to append to the packet data.
     */
    Packet &operator<<(char byte) {
        push_back(byte);
        return *this;
    }

    /**
     * \brief Retrieve the data from the packet.
     * \returns Returns the data contained by the packet.
     */
    const char *getData() const {
        return data_.data();
    }

    /**
     * \brief Get the size of the data in the packet.
     * \returns Returns the size of the data contained by the
     * packet.
     */
    int size() const {
        return size_;
    }

    /**
     * \brief Append a byte to the data.
     * @param[in] byte Byte to append to the data.
     */
    inline void push_back(char byte) {
        data_[size_++] = byte;
    }

    /**
     * \brief Access to a part of the data array.
     * @param[in] index Index of data array to be read.
     * \returns Returns the information stored at that  spot in
     * the data array.
     */
    char operator[](int index) const {
        return data_[index];
    }

    /**
     * \brief The data that has yet to be read from the packet.
     * \returns Returns the number of bytes of data that are
     * left to be read from the packet.
     */
    unsigned int dataLeftToRead() const {
        return size_ - index_;
    }

private:
    std::array<char, MAX_SIZE> data_;
    int index_;
    int size_;
};

} // Namespace mw.
