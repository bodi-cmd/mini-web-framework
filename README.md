**Tema aleasă**

Pentru acest proiect am ales sa cream un mini framework web care
faciliteaza scrierea codului HTML si JavaScript. Ca si exemplu am creat
o simpla pagina web cu un counter care poate fii incrementat, resetat,
iar la atingerea valorii 10 butonul de increment dispare.

In imaginile ce urmeaza se poate vedea diferenta de content in fisierul
de input si cel de output. In prima imagine, codul de input este
alcatuit din doua parti, prima este un fel de cod HTML, dar imbunatatit,
care contine elemente speciale cum ar fii conditia \"if\" sau variabile,
iar a doua este alcatuita din codul propriu zis care va fii transpus in
cod JavaScript, codul ce va contine funtiile de incrementare sau de
resetare a counter-ului. In cea de a doua imagine este output-ul
programului, mult mai mare ca si volum de cod fata de input.

![Codul de input](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine1.PNG)

![image](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine2.PNG)
![image](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine3.PNG)

**Explicații logică și cod**

**LEX**

Pentru partea de Lex ne-am definit cateva regex-uri specifice HTML, dar
si cateva specifice framework-ului creat de noi. Avem regexuri pentru
variabile, numere intregi si operatii.

![LEX](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine4.PNG)

**YACC**

In partea de Yacc ne-am definit structuri, arborii de parsare pentru
cele doua tipuri de cod, functii de afisare si alte funtii ajutatoare.
In acest capitol vom prezenta pe scurt ideile importante si modul de
functionare a framework-ului.

Pentru partea de cod de input de HTML, acesta suporta si traduce tag-uri
specifice HTML cum ar fii h1, div, text, button, class, span, dar avem
si imbunatatiri. Elementul \"onclick\" din HTML nu exista in
framework-ul nostru, este reprezentat de elementul \"action\". Fiecare
element declarat poate sa aiba clasa, id, actiune si conditie.

Prima imbunatatire ar fii variabilele. Putem declara variabile prin
utilizarea adnotarii @ in fata unui nume de variabila care sa inceapa cu
litera mica. Putem avea numeroare variabile, astfel incat in codul de
output de JavaScript vom avea o lista cu variabilele create, continand
numele si valoarea acestora.

Alta imbunatatire ar fii conditiile, cum ar fii \"if\". Structura este
urmatoarea: if = \[expresie\]. Asemanator cu variabilele, in codul de
Javascript tradus o sa avem o lista de conditii.

In codul de Yacc avem un contor pentru numarul de variabile create si un
contor pentru numarul de conditii create astfel incat cand se realizeaza
tradurecea sa putem crea listele si sa putem numi conditiile. Pentru a
accesa elementul specific unei conditii ii vom adauga o clasa cu numele
\"cond-with-id\" concatenat cu valoarea counter-ului, pe cand la
variabile vom adauga clasa numele_variabilei concatenat cu \"-binding\".

::: frame
HTML Code

``` {.html language="html"}
<body>  
    <div class="box">
        <h1><text>Counter:</text>@value</h1>
        <button class="box" if=[value < 10] 
            action="Increment"><text>Increment</text></button>
        <button action="Reset" ><text>Reset</text></button>
    </div>
</body>
```
:::

Pentru partea de cod din input inceputul este marcat de \"CODE_START\",
iar sfarsitul de \"CODE_END\". In interior se pot declara variabile si
functii si se pot executa expresii.

Penru a declara o variabila este necesara utilizarea cuvantului cheie
\"declare\" urmat de numele variabilei si optional \"=\" plus valoarea
dorita.

Pentru a declara o functie este necesar sa denumim functia respectiva,
numele acesteia va incepe cu litera mare pentru a o diferentia de
variabile. Se deschid acoladele, iar in interiorul acestora putem avea
declarare de variabile, asignari a unor variabile sau chiar alte
functii.

Principala structura de date a codului este:

![Stmt_node Structure](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine5.PNG)

Elementul next pointeaza la statement-ul succesor celui actual.
Statement-ul este reprezentat de un union alcatuit din urmatoarele 3
structuri:

![image](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine9.PNG)

-   o asignare, de exemplu: **value = value + 1**

![image](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine6.PNG)

-   o declarare de variabila, de exemplu: **declare value = 0**

![image](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine7.PNG)

-   o declarare de functie, de exemplu: **Reset {value = 0}**

![image](https://raw.githubusercontent.com/bodi-cmd/mini-web-framework/main/doc/Imagine8.PNG)

