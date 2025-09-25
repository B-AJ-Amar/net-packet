# Internet Protocol and UDP Documentation


## UDP Header (RFC 768)

```
0      7 8     15 16    23 24    31
+--------+--------+--------+--------+
|     Source Port      | Destination Port   |
+--------+--------+--------+--------+
|     Length           |     Checksum       |
+--------+--------+--------+--------+
```

* **Source Port:** 16 bits (0 if unused)
* **Destination Port:** 16 bits
* **Length:** header + data (min 8)
* **Checksum:** one’s complement sum over pseudo-header + UDP header + payload

  * IPv4: optional (0 = not used)
  * IPv6: mandatory

---

## UDP Message Format

```
[UDP Header][UDP Payload]
```

* **UDP Header:** 8 bytes
* **UDP Payload:** application data

  * Max IPv4 payload: 65,507 bytes (65,535 − 20 − 8)
  * Max IPv6 payload: 65,487 bytes (65,535 − 40 − 8)
  * With IPv6 jumbograms: up to ~4 GB

---

## UDP Pseudo-Headers for Checksum Calculation

### IPv4 Pseudo-Header

```
0      7 8     15 16    23 24    31
+--------+--------+--------+--------+
|       Source Address (32 bits)    |
+--------+--------+--------+--------+
|     Destination Address (32 bits) |
+--------+--------+--------+--------+
|  Zero  |Protocol|   UDP Length    |
+--------+--------+--------+--------+
```

* **Zero:** 8 bits of 0
* **Protocol:** 17 for UDP
* **UDP Length:** header + data (same as UDP header field)

