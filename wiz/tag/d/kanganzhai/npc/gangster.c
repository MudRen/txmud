// gangster.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���", ({"lou luo"}));
        set("title", WHT "����կ" NOR);

        set("gender", "����");
        set("age", 18 + random(30));
        set("long", "����һλ����կ����ޣ���Ŀ��ࡣ\n");
        set("str", 70);
        set("cor", 40);
        set("int", 20);
        set("con", 50);
        set("kar", 20);
        set("per", 20);
 
        set("kee", 1800);
        set("max_kee", 1800);
        set("gin", 300);
        set("max_gin", 300);
        set("sen", 300);
        set("max_sen", 300);
        set("force", 3000);
        set("max_force", 3000);
        set("atman", 0);
        set("max_atman", 0);
        set("mana", 0);
        set("max_mana", 0);
        set("force_factor", 50);
        set("combat_exp", 2000000);

        set_skill("unarmed", 250);
        set_skill("blade", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);

        set("inquiry", ([
        ]));

        setup();
        carry_object(__DIR__"obj/armor")->wear();
}

