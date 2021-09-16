// zhou.c

inherit NPC;

void create()
{
        set_name("���ϰ�", ({ "zhang boss","zhang" }) );
        set("gender", "����" );
        set("age", 42);
        set("long",
                "�Һ�����ϳ���һ˫������С�۾���\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;
	command("say ���̾������˵����ţ�����ȫ��Ӫҵ������׿������ӭ�ݹˡ�\n");
}