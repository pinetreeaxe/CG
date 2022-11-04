import random
import math

def generateMoons(file,rMin,rMax,rDiv, nMoons=1):
    for i in range(nMoons):
        radius = random.uniform(rMin,rMax)
        alpha = random.uniform(0,2*math.pi)
        beta = random.uniform(0,2*math.pi)
        x = math.sin(alpha) * math.cos(beta) * radius /rDiv
        y = math.sin(beta) * radius /rDiv
        z = math.cos(alpha) * math.cos(beta) * radius /rDiv
        size = random.uniform(0.1,0.3) /rDiv
        f.write('''\t\t<group>
\t\t\t<color R="0.8" G="0.8" B="0.8"/>
\t\t\t<scale X="'''+str(size)+'''" Y="'''+str(size)+'''" Z="'''+str(size)+'''"/>
\t\t\t<translate X="'''+str(x)+'''" Y="'''+str(y)+'''" Z="'''+str(z)+'''"/>
\t\t\t<models>
\t\t\t\t<model file="sphere.3d"/>
\t\t\t</models>
\t\t</group>\n''')


def translatePlanet(file, radius):
    alpha = random.uniform(0,2*math.pi)
    x = math.sin(alpha) * radius
    z = math.cos(alpha) * radius
    f.write("\t\t<translate X=\""+str(x)+"\" Y=\"0\" Z=\""+str(z)+"\"/>\n")

f = open("solarsystem.xml","w")
f.write("<scene>\n")
#sun
f.write('''\t<group>
\t\t<color R="0.9" G="0.6" B="0.1"/>
\t\t<scale X="15" Y="15" Z="15"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>
\t</group>\n''')

#mercury
f.write('''\t<group>
\t\t<color R="0.7" G="0.7" B="0.7"/>
\t\t<scale X="0.8" Y="0.8" Z="0.8"/>\n''')
translatePlanet(f,20)
f.write('''\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>
\t</group>''')

#venus
f.write('''\t<group>
\t\t<color R="0.5" G="0.5" B="0.5"/>\n''')
translatePlanet(f,30)
f.write('''\t\t<scale X="1.8" Y="1.8" Z="1.8"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>
\t</group>''')

#earth
f.write('''\t<group>
\t\t<color R="0.4" G="0.6" B="0.8"/>\n''')
translatePlanet(f,40)
generateMoons(f,3,5,2)
f.write('''\t\t<scale X="2" Y="2" Z="2"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')
f.write("\t</group>")

#mars
f.write('''\t<group>
\t\t<color R="0.8" G="0.3" B="0.1"/>\n''')
translatePlanet(f,50)
generateMoons(f,2,4,1,2)
f.write('''\t\t<scale X="1" Y="1" Z="1"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')
f.write("\t</group>")

#jupiter
f.write('''\t<group>
\t\t<color R="0.8" G="0.6" B="0.2"/>\n''')
translatePlanet(f,70)
generateMoons(f,10,15,9,79)
f.write('''\t\t<scale X="9" Y="9" Z="9"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')
f.write("\t</group>")

#saturn
f.write('''\t<group>
\t\t<color R="0.9" G="0.7" B="0.5"/>\n''')
translatePlanet(f,110)
generateMoons(f,9,15,7,62)
f.write('''\t\t<scale X="7" Y="7" Z="7"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')

#ring
f.write('''\t\t<group>
\t\t\t<color R="0.8" G="0.6" B="0.3"/>
\t\t\t<rotate angle="20" axisX="0" axisY="0" axisZ="1"/>
\t\t\t<scale X="1" Y="0.01" Z="1"/>
\t\t\t<models>
\t\t\t\t<model file="torus.3d"/>
\t\t\t</models>
\t\t</group>''')
f.write("\t</group>")

#uranus
f.write('''\t<group>
\t\t<color R="0.8" G="0.8" B="0.9"/>\n''')
translatePlanet(f,130)
generateMoons(f,6,9,4.5,27)
f.write('''\t\t<scale X="4.5" Y="4.5" Z="4.5"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')
f.write("\t</group>")

#neptune
f.write('''\t<group>
\t\t<color R="0.3" G="0.4" B="0.8"/>\n''')
translatePlanet(f,140)
generateMoons(f,6,9,4,14)
f.write('''\t\t<scale X="4" Y="4" Z="4"/>
\t\t<models>
\t\t\t<model file="sphere.3d"/>
\t\t</models>''')
f.write("\t</group>")

f.write("</scene>")