LuaQ                  $       �       CreateBoss1           U    %�  � � �@@��@� � �@����
�E �A �� \��� �� � ����  AB ܁� A� �� ��E �� �� \��� � C ��"A  KA� Ł   A� � �� � \A FA� I�D�K� �A \A�K�� ��E�\A EA K���� \����� �F�B ��A  ���B �F�� ��A  ��� �F�� ��A  ���B �F�� ��A  ��� �F� ��A  ���B �F�� ��A  �A ��F  �����FE� K���� ICIL���	 \ �A  ��FE� K����   L���	 \ �A  ��FE� K���� ICIL���	 \ �A  �A ˁ�B  ܁���� B�����	 ��F� B  
 �F�  ��K�F��\B�K�F�B
 ˂�A�
 �� �  B� ��\B  E
 K���  \�����  �B���� ��B��B ��F� �����FE K���C \��B  ��FEC K����
 \��B  ��FE�	 K��\ �B  �K ܂   @��CK  �@ ���� � A� �� �    B  �� �CCE� �� �� � A� �� �C �CD��A� �� �C �C ˃�B  ܃����D ��F	� ��D  ���� ��F	 �A �� �E � D  ���D ��F	 ��D  ���� ��F	� B� � ��D  ���D ��F	� A� � D  ����	 ��F	� D  
 �F�  ��K�F� ˄�	A� ��\D  K�F� ˄�	A� ��\D  K�F� ˄�	A� ��\D  ED K���  \�����  �D�����	 �F
 �D  �D ��F	� �����F	@��D���F	@ �D��D ˄�	B� ܄���	�E ��F� A� � E  ��	� ��F� E  
 �F
�  ��K�F
� 	\E�K�F
��\E�K�F
��	\E�EE K��
�  \�����
F �F�F ��E  ���
F �F�� ��E  ���
F �F�� ��E  ���
 �F� ��E  ���
F
 �F�F ��E  � ��  ����� �R�F � �����R�� �� AG ܆������
�� ��F  @��� � � G  � RAG �  D �E� F��� \� ���
H
 �F�� ��	 �	��G  K��
�G ˇ�A� ��\G  @���E @�� �K��
Ň ˇ�A� �� � 	 � \G  ������
F �F�F ��E  �E ��F  �����F@��E���F@ 
�E���F@�
�E�˅� @ �E��      �� ��  � AF �� �� ܅�� ��  � AF	 �� �F ܅�� ��  � A� �� �F ܅�ǅ �E      � �  � AF �� �E  � g      def 	   position    x    y    b2Vec2 ff&��   �     �@�̌�   �����������   CreateShape    e_concaveShape �    �      sprite    depth ��̽	   SetImage    Images/boss/boss.png    SetPosition gffA�̌?   SequenceGoal    Create 	   PushBack    SetImageGoal 	   WaitGoal ���=   Images/boss/boss2.png    Images/boss/boss3.png    ProbabilitySelectorGoal 	   MoveGoal    world ��LA   ?�   	   FailGoal    ParallelGoal    PlaySound2DGoal    Sounds/motor2.wav   �?   GetAvailableName    CreateBody    e_circleShape ���A
   set_scale    FunctionGoal    TargetSpawned 
   SenseGoal    player    player2    PlayMusicGoal    Chiptunes/10 Final Breath.ogg 	   M_VOLUME    MessageSendGoal 
   turretGun    ouch    MessageReceiveGoal    PrioritySelectorGoal 	   contacts    damage2    CompleteGoal 
   StopClock    TargetDestroyed 
   StopMusic    Images/boss/bossDestroyed.png    Sounds/explode_med1.wav �2      math    random �p�����  �d   ������,     ExplodeGoal    small 333?�   �      Sounds/explode_med    .wav �      PlaySoundGoal    Sounds/levelComplete.wav 	   S_VOLUME    MissionOver    SetGoal    CreateCannon    c1 ��̿��L?��L�   c2 ��̾   c3 ff&@   CreateBossTurret ���?   @       r   �    �    @� KA@ ��   \� �  ˁ�@ ��� �  A�  ��  ��   B  �  ܁ �AA����A� � B B��� ��  A�  ��  �� B ��	����� B�  D�B �   �B  ��� B � �D�� ��KE�B ���A� ��\B  KEł ���A� ��\B  KE�B ���A ��\B  KEł ���A ��\B  KE�B ���AC ��\B  KEł ���A ��\B  KE�B ���A� ��\B  KEł ���A ��\B  KE�B ���A� ��\B  KEł ���A ��\B  KE�B ���A� ��  ��  � A �D �� � � \B  KE�	 ���AC	 ��  ��	 �	 � \B  KE�B ���A�	 ��\B  KEł ���A ��\B  KE�B ���A� ��\B  KEł ���A�	 ��\B  KE�B ���A� ��\B  KE�B ���A� ��  ��  � A �D �� � � \B  KE�	 ���AC	 ��  ��	 �	 � \B  KE�B ���A�	 ��\B  KEł ���A ��\B  KE�B ���A� ��\B  KEł ���A�	 ��\B  KE�B ���A� ��\B  KE�B ���A� ��  ��  � A �D �� � � \B  KE�	 ���AC	 ��  ��	 �	 � \B  KE�B ���A�	 ��\B  KEł ���A ��\B  KE�B ���A� ��\B  KEł ���A�	 ��\B  KE�B ���A� ��\B  KEł ���A
 ��\B  KE�B ���AC ��\B  KEł ���A
 ��\B  KE�B ���A ��\B  KEł ���A
 ��\B  E� K���� \����C
 �D��
 ��
  �B  �� �D �B  �� ��D  ����EEC K���C \��B  �EE� K���� \��B  �EE� K��� \��B  �EEC K���� \��B  �EE K��\ �B  �B   A� ܂�� �D�� ��KE� \C�KE��\C�KE��\C�E� K���� \���� �D�D ��C  �� �D �C  �� ��D  ����EE� K����  �  A� � \ �C  �EE	 K���D \��C  �EED
 K��ƄN E \ �C  �EED K���� \��C  �EE K���   \ �C  �EE K��\ �C  �C ���B  ܃����D��� D��� D�����D��  � ?      GetAvailableName    GetWorldPoint    CreateBody �       target    sprite 
   set_scale ���=   CreateShape    e_circleShape 333?  �>   depth 	   SetImage    Images/boss/gun1.png    CreateJoint    e_revoluteJoint    SequenceGoal    Create 	   PushBack    SetImageGoal 	   WaitGoal �      Images/boss/gun2.png    Images/boss/gun3.png    Images/boss/gun4.png    Images/boss/gun5.png    ?
   ShootGoal    bullet    player   @B�      damage2    touch    PlaySound2DGoal    Sounds/explode1.wav �      Images/boss/gun6.png ��L=   MessageSendGoal 	   contacts    pop    CompleteGoal    Images/boss/gun1F.png    FunctionGoal    TargetShot 	   FailGoal    CreateHealthBar �      ParallelGoal    MessageReceiveGoal    ouch    ExplodeGoal    small   @?   Sounds/explode_med3.wav    name    Images/boss/gundead.png    SetPropertyGoal    PrioritySelectorGoal    SetGoal                     �   S   %^  �   A@ �� � � �  ��@ �@ ����  �  A�  �� �    B  �� �AA�ƁA���A � �A ��B A� �� ��EB � �� \���B � C ����B � AC ���A  �C�� �� A�  ��  �� B �A	�Ĉ�D� B�  BE�� �    B  � ��B � F�  ��KBFł ��A ��\B  KBF�� ��A ��\B  KBF�B ��A� �� � D �H�HA	 �D	 ��	 �	 � \B  KBF�
 ��A ��\B  KBF�
 ��AC
 ��\B  KBFł
 ��� \B  E� K��� \���B��
 F� ��B  �B�� F�C ��B  �B�
 F� ��B  �B�� F� ��B  �� �F  ����BF@ �B��BF@��B��� ��B  ܂�C��� �F� ��C  C��
 �F ��C  C���
 �F� C  � F�� ��KCF��
 ��A ��\C  KCFŃ ��AD ��\C  KCF�
 ��A ��\C  KCFŃ ��A� ��\C  E� K��  \���C� ��C��C�  �C��� �F  ����CFE� K��� \��C  �CFE� K�� \��C  �CFED K��� � A �E ��H� ��H�	 F	 A�	 ��	 \ �C  �CFE
 K�� \��C  �CFE
 K��D
 \��C  �CFE�
 K�\ �C  �� ��B� ܃�D���
 �F	 ��D  D��� �F	 ��D  D��
 �F	 ��D  D��� �F	� ��D  � F�  ��KDF� \D�KDF��\D�E� K��  \���D�� F
�� ��D  �D�
 F
� ��D  �D��
 F
 �D  �� �F	� ����DF	E�
 K�
� \��D  �DF	E� K�
�E \��D  �DF	E
 K�
� \��D  �DF	E� K�
�� \��D  ń ��	B  ܄�E�	��E�E�	� 	E�� F
�  ��KEF
Ņ ��A ��\E  KEF
�
 ��A ��\E  KEF
Ņ
 ��� \E  E� K�
�� \���E�
�
 F� ��E  �E�
� F�F ��E  �E�

 F� ��E  �E�
� F� ��E  �� �F  ����EF@ 
�E��EF@�
�E��E ��B� ܅�F�� F�F���F�F�� F�F���	F�F�� F�� F�  ��KFFņ ��F�M� � \F  KFF� ��AG ��\F  KFF�
 ��A ��\F  KFFņ
 ��� \F  E� � �� \���� �F� ����FFE� K�� H \ �F  �FFE� K�\ �F  ņ ��B  ܆�G���G�G�� G�G���G�� F�  ��KGF�� ��A�  ��  � I � \G  KGF�� ��A� ��  � � � \G  KGF�� ��AH
 ��  � 	 � \G  KGF�� ��A ��\G  KGFŇ ��AH ��\G  KGFŇ ��E� F��� � \G  KGFŇ ��E� F��� � \G  KGFŇ ��E F��� � \G  KGF�G ��A �  � \G  KGFŇ
 ��� \G  E� K��  \���G��
 F� ��G  �G��
 F �G  �G �F  ����GF@��G��GF@��G��GF@ �G�ˇR@ �G��  � K   
   turretGun    GetWorldPoint    CreateBody �       target    sprite 
   set_scale ���=   b2Vec2 33�fff�33�?333?   CreateShape    e_polygonShape   �>   depth ����	   SetImage    Images/boss/t1.png    CreateJoint    e_revoluteJoint    SequenceGoal    Create 	   PushBack    SetImageGoal    PlaySound2DGoal    Sounds/explode_med3.wav 
   ShootGoal 
   bigRocket 33����?   math    pi �   ���A�      damage2    touch 	   WaitGoal �   	   FailGoal    MessageReceiveGoal    ouch    Images/boss/t1F.png    ParallelGoal    Images/boss/t3.png ���>   Images/boss/t3F.png    Images/boss/t5.png ���@   Images/boss/t5F.png    PrioritySelectorGoal    MessageSendGoal    name    FunctionGoal    TargetShot    CreateHealthBar �   	   contacts    pop    CompleteGoal    ExplodeGoal    small   @?�������L?   Sounds/explode_med1.wav    Images/boss/t1dead.png    c1    c2    c3    SetPropertyGoal    SetGoal                                         