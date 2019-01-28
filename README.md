# libsensors

Library and tools for parsing and decoding data from [itsuhane/sensors-ios](//github.com/itsuhane/sensors-ios).

## Usage Examples

The library interface should be quite self-explanatory. Here we give examples of tools.

Preview a recorded data stream:

```bash
cat record.sensors | sensors-preview
```

(Currently, there is no limit on playback speed. So a playback may flash to the end.)

Preview real-time data stream from TCP connection:

```bash
nc 10.10.10.100 5959 | sensors-preview
```

Record the stream while keeping a preview window open:

```bash
nc 10.10.10.100 5959 | tee record.sensors >(sensors-preview) > /dev/null
```

Decode a compressed stream to uncompressed stream, then play:

```bash
nc 10.10.10.100 5959 | sensors-decode | sensors-preview
```

Receive a compressed stream, uncompress and save to record file. At the same time, keep a preview window.

```bash
nc 10.10.10.100 5959 | tee >(sensors-decode > record.sensors) >(sensors-preview) >/dev/null
```
