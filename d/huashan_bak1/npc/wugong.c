// wu_gong.c

#include <ansi.h>

inherit NPC;

void create()
{      
        set_name(HIR"ǧ�����"NOR, ({ "super wugong", "wugong" }) ); 
        set("long", 
HIR+"����һֻ�����ڻ�ɽ��������򼣬��˵�Ѿ����˽�ǧ�꣬\n"+
HIG+"�����ϵ���Ƭ��������ҫ�۵Ĺ�â��\n"NOR);   
        set("race", "Ұ��");        
        set("age", 999);        
        set("attitude", "killer");      
        set("max_gin", 5000);   
        set("max_kee", 6000);   
        set("max_sen", 4000);
    set("bellicosity", 9999);
    //set("no_exp_gain", 1);

    set("str", 120);        
    set("cor", 50); 
        set("int", 40); 
        set("kar", 40);
    set("per", 10);
    set("con", 60);
    set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );    
        set("verbs", ({ "bite", "claw" }) );

    //set_skill("unarmed",350);     
        //set_skill("parry",260);
    //set_skill("dodge",280);
    set_temp("apply/parry", 800);   
        set_temp("apply/armor", 300);
    set_temp("apply/unarmed", 800);
    set_temp("apply/dodge", 800);

    set("combat_exp", 8000000);     
        setup();
    if (random(100)>80) 
        carry_object(__DIR__"obj/dc_dan");
}
