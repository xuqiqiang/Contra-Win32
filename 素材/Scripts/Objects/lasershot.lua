LuaQ                  
      
@  E   	@ �@     d   	@��
     
@  E  	@ �@   d@  	@�� �    
   LaserShot    LaserShotMT    __index    Create    LaserShot2    LaserShot2MT           ;    
 �   ��   @�� ��D  AD  �� �    B  �� ���  A�  ��  ��E�  � ��  \����  � D ���Ń  �  AD ���B  �A�� �� AD �D �� � K�B�� \C�FCKC��� � \C FCIćEC K���� \����� �D�D �  �C  ���� �D �C  �C ��D  �����DE� K���� \��C  ��DE K���D \��C  ��DE� K���� \��C  ��DE K���D \��C  ��DE� K���� \��C  ��DE K���D \��C  ��DE� K��� \��C  ��DE K���D \��C  ��DE� K���D \��C  ��DE K���D \��C  ��DE� K���� \��C  ��DE K���D \��C  ��DE� K���� \��C  ��DE K���D \��C  � ˃�B  ܃���� D����D ��D	� ��D  D �D�  ��K�D��\D�K�D�� ˄�	A	 �E  �E	  �� \D  E K���� \�����  �D���� ��D��D ��D	  �����D	E K��
��\��D  ��D	E�	 K��
�E  �	 \ �D  ��D	E
 K��
�	 \��D  ��D	EE
 K��
\ �D  � ˄�	B  ܄���	��E���	� 	E��J��	E��  � +      CreateBody �       b2Vec2 �������>���?   CreateShape    e_polygonShape �      ?	   SetImage    Images/boss3/shot1.png    sprite 
   set_scale ���=   depth �����   SequenceGoal    Create 	   PushBack    MessageSendGoal 	   contacts    CompleteGoal    SetImageGoal 	   WaitGoal 
ף=   Images/boss3/shot2.png    Images/boss3/shot3.png    Images/boss3/shot4.png    Images/boss3/shot5.png    Images/boss3/shot6.png    Images/boss3/shot7.png    ParallelGoal 	   StopGoal )\?   MoveLVGoal    self �d   	   FadeGoal   �>   DestroyBodyGoal 	   FailGoal    SetGoal                     C   �       �� @ ���  �AD  �D  ��   B  �  ܂ �  C �@@ �� ��@A@ ��� ���A@ �� ��@B@ ��� ���B@ �� � �@C  ��� ��� A �D ��E� �� �D \���� ��   �����  @ ���C  @����E ���D E AE �� ܃ ���E�� �� D ��	DF�� �F�� ��KG�D ���	A� � � \D  KG�� ���	� \D  E� K���  \��� �DH	�D �� @C	����� �F
�� ��D  @���� �F
�	 ��D  ��E	 �F
� ��	 ����D  ���	 �F
�
 ��D  �� ���  ��� ���  ��D ���  ���  ���  ��D
 ���  ���
 �D   	AE ����EF	 K���   A�
 �F�G  N��\��E  ��E�	 K���F \��E  �D�ń ���	B� ܄��	�E	 ��F  @ 	��
 �AF  �����E  �	��	 ��F� ��E  �	�E	 ��F  @ 	�� �AF  �����E  �	��	 ��F� ��E  � �F
�  ��KG
��\E�KG
��	\E�E K��
�  \����
  
�E���
F �F�� ��E  � ��F  ����G@�
�E��G@ �E�Ņ ���B  ܅����	 ��F���F  ��� ��FG  A � F  ��F ��F� ��F  ��� ��F� F   �F�  ��KG� \F�KG��\F�K�� \F��  � 9      CreateBody �       Images/explosion/lz �   33KA�   333A�   33A�   33A�   ff�@�   ff�@   b2Vec2 ��̽�������=   CreateShape    e_concaveShape    ?   sprite 
   set_scale    depth �����   SequenceGoal    Create 	   PushBack    MessageSendGoal 	   contacts    CompleteGoal    math    random    PlaySound2DGoal    Sounds/lz2.wav    Sounds/lz1.wav    SetImageGoal    1.png 	   WaitGoal 
�#=�   �      .png �	   
ף<��L=   b.png    ParallelGoal 	   StopGoal �'  	   FadeGoal   �>   DestroyBodyGoal    self 	   FailGoal    SetGoal                             