## Generate UID for Components
```bash
uuidgen | tr -d '-' | sed -E 's/(........)(........)(........)(........)/0x\1, 0x\2, 0x\3, 0x\4/'
```