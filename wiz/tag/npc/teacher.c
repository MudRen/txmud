#include <ansi.h>

inherit NPC;

void create()
{
    set_name("������", ({ "liu wenzhang" }) );
    set("gender", "����");
    set("age", 62);
    set("nick", "$HIW$ѧ�����Ŀ�����$NOR$");
    set("long",
    "������������ׯ���ѧ֮ʿ�������������ŵڡ����������ʱ��ȫ��\n"
    "�⵽��ɱ��ֻ����һ���˻���������\n"
    );

    set("inquiry", ([
        "here" : "�����������ׯ��ѧ�ð�����λ*����ʲô���飿\n" ,
        "rumors" : "������������겻�Ž����£�*����ȥ�������ʰɡ�\n" ,
        "name" : "�������������¡�\n" ,
        "������" : "������������£���λ*���������ʲô���飿\n" ,
    ]));

    set("attitude", "peaceful");
    set("str", 25); 
    set("con", 20); 
    set("kar", 20); 
    set("cor", 15); 
    set("int", 80); 
    set("per", 25); 
    set("combat_exp", 500000); 
    set("max_kee",2000);
    set("max_gin",1000);
    set("max_sen",1000);
    set("force",200);
    set("max_force",200);
    set("force_factor",0);

    set_skill("literate", 300);


    setup();
    carry_object(ARMOR_DIR"cloth")->wear();
}
