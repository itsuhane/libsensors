# libsensors

Library and tools for parsing and decoding data from [itsuhane/sensors-ios](//github.com/itsuhane/sensors-ios).

## Usage Examples

The library interface should be quite self-explanatory. Here we give examples of tools.

Preview a recorded data stream

```bash
cat record.sensors | sensors-preview
```

Preview real-time data stream from TCP connection

```bash
nc 10.10.10.100 5959 | sensors-preview
```
