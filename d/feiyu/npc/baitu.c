#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"С����"NOR, ({ "xiao baitu", "baitu" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻѩ��Ư����С���á�\n");
        set("attitude", "peaceful");
 
        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 100);

        set_temp("apply/attack", 10);
        set_temp("apply/damage", 6);
        set_temp("apply/defence",10);
        set_temp("apply/armor",10);

        setup();
}

void die()
{
        object ob;
        message_vision("\n$N���˼�����$N���ˡ�\n", this_object());
        ob = new(__DIR__"obj/turou");
        ob->move(environment(this_object()));
        destruct(this_object());
}

