LuaQ                  $              CreatePowerUp           m     Q    ΛA@ ά @ ΐ   A    Α   B   Β   AΒ      A  AC A ΑΓ   B  B BBB A B BΫB  Α Β@Cΐ C  AΓ B 	BD	BDΐΔ ΒDΑB  ΐA@ Α ΐE@ Α  @F@ Α ΐF@ Α  ΐ@@ Α@    Α  ΕΒ ΛΘB άΕ@ Γ AC Γ  ΘΔ H		 @E	 
D  Θ	 H	 D  Γϋ $ Ζ@ Γ AC Γ  ΘΔ H	Ε	 @E	 
D  Θ	 H	 D  Γϋ Ζ@ Γ AC Γ  ΘΔ H	
 @E	 
D  Θ	 H	 D  Γϋ  Η@ Γ AC Γ  ΘΔ H	E
 @E	 
D  Θ	 H	 D  Γϋ Κ@
 Γ AC Γ  ΘΔ H	Ε
 @E	 
D  Θ	 H	 D  Γϋ Η@ Γ AC Γ  ΘΔ H	 @E	 
D  Θ	 H	 D  Γϋ W@Λ@ @Η Γ AC Γ  ΘΔ H	 @E	 
D  Θ	 H	 D  ΓϋΓ H  KHΕΓ ΛΘA ά\C  KHΕC ΛΘA  ά \C  KHΕΓ ΛΘA   ΑΔ E ά \C  KHΕ ΛΘAΔ ά\C  EΓ KΘΒ  \ΘD H Α  C  ΘD H C   H   @ΕΓ ΛΘB  άΘΔ H	Ε A   ΐ  D  Θ H	Ε D  HDΛH@άCΛH@ άCΛH@άCΛCO@ άC  >   ώ       GetAvailableName    CreateBody ώ      CreateShape    e_circleShape 333?ώ      sprite 
   set_scale ΝΜΜ=   depth ffΐ    ApplyImpulse ώ   
   isPowerup    agent    random    math ώ
      flame ώ      missle ώ      granade ώ      gun    spread2    health    SequenceGoal    Create ώ   	   PushBack    SetImageGoal    Images/powerups/f    .png 	   WaitGoal    Images/powerups/r    Images/powerups/g    Images/powerups/m    spread    Images/powerups/s    Images/powerups/h    laser    Images/powerups/l    MessageReceiveGoal    touch    MessageSendGoal 	   contacts    PlaySound2DGoal    Sounds/powerup.wav    ?   DestroyBodyGoal    self    pop    CompleteGoal    ParallelGoal 	   MoveGoal    Β   SetGoal                             