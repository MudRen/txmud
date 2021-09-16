//tree_guardian.c �����Ի���
inherit NPC;
void create()
{
        set_name("��֥�Ի�", ({ "linzhi hunter"}) );
        set("gender", "����");
        set("age", 27);
        set("long","����һλ����ʥ�����Ի���ֻ����һ�������ɷ��ģ����\n");
        set("combat_exp", 2000000);
        set("str",80);
        set("con",40);
        set("kar",40);
        set("max_force",4000);
        set("force",8000);
        set("force_factor",300);
        set("max_atman",1500);
        set("atman",1500);
        set("max_mana",1500);
        set("mana",1500);
        set("max_kee",3000);
        set("max_gin",2000);
        set("max_sen",2000);
        set("attitude", "heroism");
        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("fork", 250);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("ganchan", 250);
        set_skill("qiuyue-fork", 250);
        map_skill("dodge","ganchan");
        map_skill("fork","qiuyue-fork");
        map_skill("parry","qiuyue-fork");
        setup();
        carry_object(__DIR__"obj/hunt-fork")->wield();
        carry_object(__DIR__"obj/teng-armor")->wear();
}
int heal_up()
{
        if( environment() && living(this_object()) && !is_fighting() )
        {
                call_out("do_leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}
void do_leave()
{
        string *dirs;
        mapping exits;
        exits = environment()->query("exits");
        if(!sizeof(exits))
                tell_room(environment(),name()+"�Ҵ�ææ�����ˡ�\n");
        else
        {
                dirs = keys(exits);
                message_vision(sprintf("$N��%s�뿪��\n",to_chinese(dirs[random(sizeof(dirs))])),this_object());
        }
        destruct(this_object());
}
void die()
{
        object winner=query_temp("last_damage_from");
        winner->set_temp("mark/ʥ��",1);
        return;
}
