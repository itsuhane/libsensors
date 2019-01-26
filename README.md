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

Recording the stream while keeping a preview window open:

```bash
nc 10.10.10.100 5959 | tee record.sensors >(sensors-preview) > /dev/null
```
