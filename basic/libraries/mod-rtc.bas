     �     �     �     �     �     RTC.MODE�    RTC.DETECT�     �    RTC.READTIME�     �     �     �    RTC.READ�    RTC.READDATE�     �    RTC.WRITETIME�    RTC.WRITE�    RTC.WRITEDATE�     �     �     �
     YEA�     MONT�	     DA�     HOUR�
     MIN�
     SEC�                                                                                                                                                                                                                          P  ̀I-------------------------------------------------------------------------�  ��"  ̀I2C Real Time Click Library�  ̀	supports:�  ̀$51 - PCF 8563 UEXT��  ̀�$68 - DS3231(m) (Olimex UEXT module) / DS1307 clock + RAM only ( note: PCF8623 uses this same address but with different register layout)�  ̀$69 - MAX31341�  ̀$6F - MCP7940N�  ��P  ̀I-------------------------------------------------------------------------�  ���   %0@�d  ̀]Detect RTC clock - c returns > 0 if a RTC is detected. Could be a capability bitmap in future�  � 4� E��  ����AQο %0�AQ� E0�A�  ����Ahο %0�Ah� E0�A�  ����Aiο %0�Ai� E0�A�  ����Aoο %0�Ao� E0�A�  ��  ̀Read Hours/Mins/Secs�  � L� _�� f�� m��  � %0�AQ�  � t _��� %ʁD�(���  � t f��� %ʁC�(�A��  � t m��� %ʁB�(�A��  ��  �� %0�Ah�)� %0�Ao��  � t _��� %ʁB�(���  � t f��� %ʁA�(�A��  � t m��� %ʁ@�(�A��  Ѳ %0�Ai�  � t _��� %ʁH�(���  � t f��� %ʁG�(�A��  � t m��� %ʁF�(�A��  ��  ��  ��  ��  ̀Read Year/Month/Day�  � �� �� f�� ���  � %0�AQ�  � t ��� %ʁH�(�A��  � t f��� %ʁG�(�_��  � t ���� %ʁE�(���   0  _P�  ��  �� %0�Ah�)� %0�Ao��  � t ��� %ʁF�(�A��  � t f��� %ʁE�(�_��  � t ���� %ʁD�(���   0  _P�  ��  � %0�Ai�  � t ��� %ʁL�(���  � t f��� %ʁK�(�A��  � t ���� %ʁJ�(�A��   0  _P�  ��  ��  ��  ��  ̀Write Hours/Mins/Secs�  � � _� f� m��  � %0�AQ�  � ��D� _��  � ��C� f��  � ��B� m��  ��  �� %0�Ah�)� %0�Ao��  � ��B� _��  � ��A� f��  � ��@� m��  ��  � %0�Ai�  � ��H� _��  � ��G� f��  � ��F� m��  ��  ��  ��  ��  ̀Write Year/Month/Day�  � � � f� ���  � %0�AQ�  � ��H� &Ad��  � ��G� f��  � ��E� ���  ��  �� %0�Ah�)� %0�Ao��  � ��F� &Ad��  � ��E� f��  � ��D� ���  ��  � %0�Ai�  � ��L� &Ad��  � ��K� f��  � ��J� ���  ��  ��  ��  ��  ��  � t� �� ���   �0� �$D�"J � �(O��  ��  ��  � � �� ���#   �0� �&J� �� �'J�%D���� %� �� ��  ��  �����$�̀Demo code: NEW to remove this���� E0@�
� 4 E��	� E+@�$� �_h�C�S��.� �Q�y�@��8��B���L� � �� �� ���� �� �� ��V� L��������`��r�j���t�� 