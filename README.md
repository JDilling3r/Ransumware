# Ransumware
Fake Ransomware to aid in training. 

- Changes all files in user home directory to <FILE>.ransum
- Changes Background to image
- Displays dialog "scareware" message info and asks user to click "I understand" radio
- Takes password as input to "decrypt" files 
- Edits registry to create icon image for .ransum file extension 

This application does NOT
- Encrypt files
- Delete data
- Create persistence
- Edit anything above or below User's Desktop folder. 

  # To Do
  - Create gui layer to edit and dynamically create compiled code
  - Clean code
  - Add auto-clean up count down (desired effect lasting x minutes long upon running then self destruct)
  
  # AV
  - Although nothing truly malicious is happening, Norton AV flags for file manipulation (Mcafee, WindowsDefender does not)
