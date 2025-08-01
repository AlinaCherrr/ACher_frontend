#include "bitset.hpp"

std::vector<uint32_t> BitSet::SameSize(const BitSet& lhs, const BitSet& rhs) {
    int32_t max_size = std::max(lhs.size_, rhs.size_);
    std::vector<uint32_t> rez(max_size);
    std::copy(lhs.bits_.begin(),lhs. bits_.end(), rez.begin() + (max_size - lhs.size_));
    return rez;
}

BitSet::BitSet(const BitSet& rhs)
{
    size_ = rhs.size_;
    bits_.resize(size_);
    std::copy(rhs.bits_.begin(), rhs.bits_.end(), bits_.begin());
}

BitSet::BitSet(BitSet&& rhs) noexcept
{
    std::swap(size_, rhs.size_);
    std::swap(bits_, rhs.bits_);
}

BitSet& BitSet::operator=(const BitSet& rhs)
{
    if (this != &rhs) {
        size_ = rhs.size_;
        bits_.resize(size_);
        std::copy(rhs.bits_.begin(), rhs.bits_.end(), bits_.begin());
    }
    return *this;
        
}

BitSet& BitSet::operator=(BitSet&& rhs) noexcept
{
    std::swap(size_, rhs.size_);
    std::swap(bits_, rhs.bits_);
    return *this;

}

bool BitSet::operator==(const BitSet& rhs) const noexcept
{
    return bits_ == rhs.bits_;
}

bool BitSet::operator!=(const BitSet& rhs) const noexcept
{
    return !operator==(rhs);
}

void BitSet::Resize(const std::int32_t size)
{
    size_ = size;
    bits_.resize(size);
}

bool BitSet::Get(const int32_t idx) const
{
    if (idx >= 0 && idx < size_) {
        return bits_[idx];
    }
    else {
        throw std::out_of_range("Incorrect index");
    }
}

void BitSet::Set(const int32_t idx, const bool val)
{
    if (idx >= 0 && idx < size_) {
        bits_[idx] = val;
    }
    else {
        throw std::out_of_range("Incorrect index");
    }
}

void BitSet::Fill(const bool val) noexcept
{
    std::fill(bits_.begin(), bits_.end(), val);
}


BitSet BitSet::operator~()
{
    BitSet rez(size_);
    for (uint32_t i = 0; i < size_; i++) {
        bool temp = static_cast<bool>(bits_[i]);
        rez.bits_[i] = !temp;
    }
    return rez;
}

BitSet& BitSet::operator|=(const BitSet& rhs)
{
    std::vector<uint32_t> a = SameSize(*this, rhs);
    std::vector<uint32_t> b = SameSize(rhs, *this);
    size_ = a.size();
    bits_.resize(a.size());
    for (int32_t i = 0; i < a.size(); i++) {
        bits_[i] = (a[i] | b[i]);
    }
    return *this;
}

BitSet& BitSet::operator&=(const BitSet& rhs)
{
    std::vector<uint32_t> a = SameSize(*this, rhs);
    std::vector<uint32_t> b = SameSize(rhs, *this);
    size_ = a.size();
    bits_.resize(a.size());
    for (int32_t i = 0; i < a.size(); i++) {
        bits_[i] = (a[i] & b[i]);
    }
    return *this;
}

BitSet& BitSet::operator^=(const BitSet& rhs)
{
    std::vector<uint32_t> a = SameSize(*this, rhs);
    std::vector<uint32_t> b = SameSize(rhs, *this);
    size_ = a.size();
    bits_.resize(a.size());
    for (int32_t i = 0; i < a.size(); i++) {
        bits_[i] = (a[i] ^ b[i]);
    }
    return *this;
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs)
{
    BitSet a = lhs;
    a &= rhs;
    return a;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs)
{
    BitSet a = lhs;
    a |= rhs;
    return a;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs)
{
    BitSet a = lhs;
    a ^= rhs;
    return a;
}



BitSet::BiA& BitSet::BiA::operator=(const BiA& bia) {
    b_.bits_[i_] = bia.b_.bits_[bia.i_];
    return *this;
}


std::ostream& BitSet::WriteTxt(std::ostream& ostrm) const
{
    std::uint32_t counter = 0;

    ostrm << size_ << std::endl;
    for (size_t i = 0; i != size_; ++i) {
        ostrm << bits_[i];
        if ((i + 1) % 20 == 0) {
            ostrm << ' ' << counter++ << std::endl;
        }
        
    }
    if (size_ % 20 != 0) {
        std::string end(20 - size_ % 20 + 1, ' ');
        ostrm << end << counter << std::endl;
    }
    return ostrm;
}

std::istream& BitSet::ReadTxt(std::istream& istrm)
{
    istrm >> size_;
    std::string bits;
    istrm >> bits;

    if (bits.size() != size_) {
        throw std::logic_error("Incorrect number of characters");
    }

    if (istrm.good()) {
        for (char const& c : bits) {
            if (!istrm || (c != '1' && c != '0')) {
                istrm.setstate(std::ios_base::failbit);
                return istrm;
            }
            else {
                bits_.push_back(c - '0');
            }
        }
    }


    return istrm;
}


const BitSet::BiA& BitSet::BiA::operator=(const BiA& bia) const {
    b_.bits_[i_] = bia.b_.bits_[bia.i_];
    return *this;
}

bool BitSet::BiA::operator==(const BiA& bia)
{
    return b_.bits_[i_] == bia.b_.bits_[i_];
}

bool BitSet::BiA::operator==(const bool value)
{
    return b_.bits_[i_] == value;
}

bool BitSet::BiA::operator!=(const BiA& bia)
{
    return b_.bits_[i_] != bia.b_.bits_[i_];
}

bool BitSet::BiA::operator!=(const bool value)
{
    return b_.bits_[i_] != value;
}
