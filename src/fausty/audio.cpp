#include <cstring>

#include "audio.h"

unsigned int Audio::frames_ = 512;
unsigned int Audio::sampleRate_ = 44100;

Audio::Audio(const Audio &other)
{
  format_ = other.format_;
  frames_ = other.frames_;
  impl_ = other.impl_;
}
Audio::Audio(fy_real *raw, size_t nChannels)
{
  format_ = ChannelCountToFormat(nChannels);
  switch (nChannels)
  {
  case 1:
    // format_ = Format::kMono;
    impl_ = AudioImplPtr(new AudioImplT<1>(raw));
    break;
  case 2:
    // format_ = Format::kStereo;
    impl_ = AudioImplPtr(new AudioImplT<2>(raw));
    break;
  case 4:
    // format_ = Format::kQuad;
    impl_ = AudioImplPtr(new AudioImplT<4>(raw));
    break;
  case 6:
    // format_ = Format::k5_1;
    impl_ = AudioImplPtr(new AudioImplT<6>(raw));
    break;
  default:
    // format_ = Format::kNull;
    impl_ = nullptr;
    break;
  }
}
Audio::Audio(Format format) : format_(format)
{
  switch (format)
  {
  case Format::kMono:
    impl_ = AudioImplPtr(new AudioImplT<1>());
    break;
  case Format::kStereo:
    impl_ = AudioImplPtr(new AudioImplT<2>());
    break;
  case Format::kQuad:
    impl_ = AudioImplPtr(new AudioImplT<4>());
    break;
  case Format::k5_1:
    impl_ = AudioImplPtr(new AudioImplT<6>());
    break;

  default:
    impl_ = nullptr;
    break;
  }
}

void Audio::WritePlanar(fy_buffer_t out, fy_real scale)
{
  xt::xarray<fy_real> arr = array();
  if (scale != 1.0)
  {
    arr = arr * scale;
  }
  size_t channels = nChannels();
  for (size_t i = 0; i < channels; ++i)
  {
    memcpy(out, &arr(i), frames_ * sizeof(fy_real));
    out += frames_;
  }
}

// Utilities
Audio::Format Audio::ChannelCountToFormat(int count)
{
  switch (count)
  {
  case 1:
    return Format::kMono;
  case 2:
    return Format::kStereo;
  case 4:
    return Format::kQuad;
  case 6:
    return Format::k5_1;
  default:
    return Format::kNull;
  }
  // return Audio::Format::kNull;
}

int Audio::FormatToChannelCount(Audio::Format format)
{
  switch (format)
  {
  case Audio::Format::kMono:
    return 1;
  case Audio::Format::kStereo:
    return 2;
  }
  return 0;
}

Audio Audio::Convert(Audio::Format toFormat)
{
  switch (format_)
  {
  case Format::kMono:
  {
    switch (toFormat)
    {
    case Format::kStereo:
      return ConvertMonoToStereo();

    default:
      return Audio();
    }
  }
  case Format::kStereo:
  {
    switch (toFormat)
    {
    case Format::kMono:
      return ConvertStereoToMono();

    default:
      return Audio();
    }
  }

  default:
    return Audio();
  }
}

Audio Audio::ConvertMonoToStereo()
{
  Audio audio(Format::kStereo);

  xt::xarray<fy_real> arr = array();
  for (size_t i = 0; i < 2; ++i)
  {
    memcpy(audio.buffers()[i], &arr(0), frames_ * sizeof(fy_real));
  }

  return audio;
}

Audio Audio::ConvertStereoToMono()
{
  Audio audio(Format::kMono);

  xt::xarray<fy_real> arr = array();
  // TODO: Cheat and just copy the first channel
  for (size_t i = 0; i < 1; ++i)
  {
    memcpy(audio.buffers()[i], &arr(0), frames_ * sizeof(fy_real));
  }

  return audio;
}