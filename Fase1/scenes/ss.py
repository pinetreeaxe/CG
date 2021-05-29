import random
import math


def generateMoons(file,rMin,rMax,rDiv, nMoons=1):
    for i in range(nMoons):
        rTime = random.uniform(0.5,1)
        radius = random.uniform(rMin,rMax)
        alphaini = random.uniform(0,2*math.pi)
        size = random.uniform(0.1,0.3) /rDiv
        f.write('''\t\t<group>
\t\t\t<color R="0.8" G="0.8" B="0.8"/>
\t\t\t<scale X="'''+str(size)+'''" Y="'''+str(size)+'''" Z="'''+str(size)+'''"/>
\t\t\t<translate time="'''+ str(rTime) +'''">\n''')
        for j in range(0,10):
            alpha = alphaini + ((j * (360/10) * math.pi)/180)
            x = math.sin(alpha) * radius /rDiv
            z = math.cos(alpha) * radius /rDiv
            f.write("\t\t\t\t   <point X=\""+str(round(x,6))+"\" Y=\"0\" Z=\""+str(round(z,6))+"\"/>\n")
        f.write("\t\t</translate>")
        f.write('''
\t\t\t<models>
\t\t\t\t<model file="sphere.3d" texture="moon.jpg"/>
\t\t\t</models>
\t\t</group>\n''')



def translatePlanet(file, radius,pointsNum,time):
    f.write("\t\t<translate time=\""+str(time)+"\">\n")
    for i in range(0,pointsNum):
        alpha = (i * (360/pointsNum) * math.pi)/180
        x = math.sin(alpha) * radius
        z = math.cos(alpha) * radius
        f.write("\t\t\t<point X=\""+str(round(x,6))+"\" Y=\"0\" Z=\""+str(round(z,6))+"\"/>\n")
    f.write("\t\t</translate>\n")

def rotatePlanet(file,angle,time,x,y,z):
    f.write("\t\t<rotate angle=\""+str(angle)+"\" axisX=\""+str(x)+"\" axisY=\""+str(y)+"\" axisZ=\""+str(z)+"\" time=\""+str(time)+"\" />\n")

f = open("solarsystem.xml","w")
f.write("<scene>\n")
#sun
f.write('''\t<lights>
\t\t<light type="POINT" posX="0.0" posY="0.0" posZ="0.0" />
\t\t<light type="POINT" posX="0.0" posY="0.0" posZ="0.0" />
\t\t<light type="POINT" posX="0.0" posY="0.0" posZ="0.0" />
\t\t<light type="POINT" posX="0.0" posY="0.0" posZ="0.0" />
\t\t<light type="POINT" posX="0.0" posY="0.0" posZ="0.0" />
\t</lights>
\t<group>
\t\t<color R="0.9" G="0.6" B="0.1"/>
\t\t<scale X="15" Y="15" Z="15"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="sun.jpg" emissR="1.0" emissG="1.0" emissB="1.0"/>
\t\t</models>
\t</group>\n''')

#mercury
f.write('''\t<group>
\t\t<color R="0.7" G="0.7" B="0.7"/>
\t\t<scale X="0.8" Y="0.8" Z="0.8"/>\n''')
translatePlanet(f,20,10,1)
rotatePlanet(f,0,0.1,0,1,0)
f.write('''\t\t<models>
\t\t\t<model file="sphere.3d" texture="mercury.jpg"/>
\t\t</models>
\t</group>''')

#venus
f.write('''\t<group>
\t\t<color R="0.5" G="0.5" B="0.5"/>\n''')
translatePlanet(f,30,10,2)
rotatePlanet(f,0,0.1,0,1,0)
f.write('''\t\t<scale X="1.8" Y="1.8" Z="1.8"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="venus.jpg"/>
\t\t</models>
\t</group>''')

#earth
f.write('''\t<group>
\t\t<color R="0.4" G="0.6" B="0.8"/>\n''')
translatePlanet(f,40,20,3)
rotatePlanet(f,0,0.1,0,1,0)
generateMoons(f,3,5,2)
f.write('''\t\t<scale X="2" Y="2" Z="2"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="earth.jpg"/>
\t\t</models>''')
f.write("\t</group>")

#mars
f.write('''\t<group>
\t\t<color R="0.8" G="0.3" B="0.1"/>\n''')
translatePlanet(f,50,20,5)
rotatePlanet(f,0,0.1,0,1,0)
#generateMoons(f,2,4,1)
f.write('''\t\t<scale X="1" Y="1" Z="1"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="mars.jpg"/>
\t\t</models>''')
f.write("\t</group>")

#jupiter
f.write('''\t<group>
\t\t<color R="0.8" G="0.6" B="0.2"/>\n''')
translatePlanet(f,70,30,10)
rotatePlanet(f,0,0.1,0,1,0)
#generateMoons(f,10,15,9)
f.write('''\t\t<scale X="9" Y="9" Z="9"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="jupiter.jpg"/>
\t\t</models>''')
f.write("\t</group>")

#saturn
f.write('''\t<group>
\t\t<color R="0.9" G="0.7" B="0.5"/>\n''')
translatePlanet(f,110,40,20)
rotatePlanet(f,0,0.1,0,1,0)
#generateMoons(f,17,25,7)
f.write('''\t\t<scale X="7" Y="7" Z="7"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="saturn.jpg"/>
\t\t</models>''')

#ring
f.write('''\t\t<group>
\t\t\t<color R="0.8" G="0.6" B="0.3"/>
\t\t\t<scale X="1" Y="0.01" Z="1"/>
\t\t\t<models>
\t\t\t\t<model file="torus.3d" texture="ring.jpg"/>
\t\t\t</models>
\t\t</group>''')
f.write("\t</group>")

#uranus
f.write('''\t<group>
\t\t<color R="0.8" G="0.8" B="0.9"/>\n''')
translatePlanet(f,130,60,40)
rotatePlanet(f,0,0.1,0,1,0)
#generateMoons(f,6,9,4.5)
f.write('''\t\t<scale X="4.5" Y="4.5" Z="4.5"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="uranus.jpg"/>
\t\t</models>\n''')
f.write("\t</group>\n")

#comet
f.write('''\t<group>
\t\t<color R="0.2" G="0.3" B="0.4"/>
\t\t<translate time="5">
\t\t\t<point X="0" Y="0" Z="125" />
\t\t\t<point X="19" Y="0" Z="115" />
\t\t\t<point X="27" Y="0" Z="105" />
\t\t\t<point X="33" Y="0" Z="95" />
\t\t\t<point X="38" Y="0" Z="85" />
\t\t\t<point X="42" Y="0" Z="75" />
\t\t\t<point X="45" Y="0" Z="65" />
\t\t\t<point X="46" Y="0" Z="55" />
\t\t\t<point X="47" Y="0" Z="45" />
\t\t\t<point X="46" Y="0" Z="35" />
\t\t\t<point X="45" Y="0" Z="25" />
\t\t\t<point X="42" Y="0" Z="15" />
\t\t\t<point X="38" Y="0" Z="5" />
\t\t\t<point X="33" Y="0" Z="-5" />
\t\t\t<point X="27" Y="0" Z="-15" />
\t\t\t<point X="19" Y="0" Z="-25" />
\t\t\t<point X="0" Y="0" Z="-35" />
\t\t\t<point X="-19" Y="0" Z="-25" />
\t\t\t<point X="-27" Y="0" Z="-15" />
\t\t\t<point X="-33" Y="0" Z="-5" />
\t\t\t<point X="-38" Y="0" Z="5" />
\t\t\t<point X="-42" Y="0" Z="15" />
\t\t\t<point X="-45" Y="0" Z="25" />
\t\t\t<point X="-46" Y="0" Z="35" />
\t\t\t<point X="-47" Y="0" Z="45" />
\t\t\t<point X="-46" Y="0" Z="55" />
\t\t\t<point X="-45" Y="0" Z="65" />
\t\t\t<point X="-42" Y="0" Z="75" />
\t\t\t<point X="-38" Y="0" Z="85" />
\t\t\t<point X="-33" Y="0" Z="95" />
\t\t\t<point X="-27" Y="0" Z="105" />
\t\t\t<point X="-19" Y="0" Z="115" />
\t\t</translate>
\t\t<scale X="0.7" Y="0.7" Z="0.7"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')
f.write("\t</group>")

#neptune
f.write('''\t<group>
\t\t<color R="0.3" G="0.4" B="0.8"/>\n''')
translatePlanet(f,140,120,100)
rotatePlanet(f,0,0.1,0,1,0)
#generateMoons(f,6,9,4)
f.write('''\t\t<scale X="4" Y="4" Z="4"/>
\t\t<models>
\t\t\t<model file="sphere.3d" texture="neptune.jpg"/>
\t\t</models>''')
f.write("\t</group>")

f.write("</scene>")