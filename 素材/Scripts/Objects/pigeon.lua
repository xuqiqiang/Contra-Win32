LuaQ                  $       �       CreatePigeon           `     �  @ � KA@ �  � @ ��  ��  �  B� �  �    \� ����AB AB �A ���� A ��  ��  �  B� �A �A�� �A��������� �AC�� �� �C ������A� �B �A � �A�B  ܁����� �BDC ��B  ���� �BD ��B  ���� �BDC ��B  � BD�� ��K�D�� �B�A� ��\B  K�D��\B�K�D�� �B�A ��\B  K�D�� �B�A ��\B  K�D�� �B�AC ��\B  K�D�� �B�A ��\B  E� KB��  \������ CD�� � D ��B  ���� CD �B  �� �BD  ���˂DE� KC�� \��B  ˂DE� KC�\ �B  ł �B�B  ܂����� �CDD ��C  ���� �CD� C  � CD�  ��K�D�� �C�A� ��\C  K�DŃ �C�� \C  E� KC��  \������ DD�� ��C  ���� DD �C  �� �CD  ���˃DE� KD��	 \��C  ˃DE� KD�\ �C  Ń �C�B  ܃����� �DD	E	 ��D  ���� �DD	� D  �	 DD�� ��K�D� \D�K�D��\D�K�D� \D�K�D��\D�K�D� \D�K�D��\D�K�D� \D�K�D��\D�E� KD��� \������ ED
��	 ��D  ���� ED
�
 ��D  ���� ED
�E
 ��D  ���� ED
�
 ��D  ���� ED
��
 ��D  ���� ED
�
 ��D  ���� ED
��
 ��D  ���� ED
�
 ��D  ���� ED
� ��D  ���� ED
�
 ��D  ���� ED
�E ��D  ���� ED
�
 ��D  �� �DD	� ���� �D�	� A� ܄� EC
A� � ��E FE�
�� � \���C@���D	F FD�� ���G�@�	 �E   ���D	F FD�� ��G�@�	 �E  ��D	� FD �E  ��	 �ED  ���˅D@��E�˅D@ 	�E��E �E�B  ܅���� F���� F����� �FD� ��F  ����F� � 8      GetAvailableName    CreateBody �       sprite 
   set_scale ���=   CreateShape    e_circleShape ff@	   SetImage    Images/bird/land1.png    depth    math    random �   ��̽   ProbabilitySelectorGoal    Create 	   PushBack 	   WaitGoal ��L>���>   SequenceGoal    SetImageGoal    Images/bird/land2.png    Images/bird/land3.png 
   RangeGoal    player ��A   player2 	   FailGoal    MessageReceiveGoal    shot1    shot2    shot3    shot4    shot5    shot6    ParallelGoal    Images/bird/fly1.png ��u=   Images/bird/fly2.png    Images/bird/fly3.png    Images/bird/fly4.png    Images/bird/fly5.png    Images/bird/fly6.png �
   �   �   	   MoveGoal    self ��L���L@   PrioritySelectorGoal    DestroyBodyGoal    SetGoal                             