// jiang.c

inherit NPC;

void create()
{
        set_name("���䳬", ({ "jiang ling chao" }) );

	set("title","�����ϰ�");
        set("gender", "����" );
        set("age", 68);
        set("long","���µĲ�ɣ������������������ĺۼ���\n");
        set("combat_exp", 200);
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

	if(!random(3))
		command("say ����ȫ��Ӫҵ������׿������ӭ�ݹˡ�\n");
}

