// shenmi.c

inherit NPC;

int ask_me(object me);

void create()
{
        set_name("��������", ({ "shenmi man","man"}) );
        set("gender", "����" );
        set("age", 23);
        set("attitude", "peaceful");
        set("per",30);
        set("combat_exp",100);
        set("inquiry", ([
                "ҹ��" : ("ҹ�����ҵ����ӣ���ס�������\n"),
                "����" : (: ask_me :),
        ]) );

        set("long","����һλ���صİ������ӣ����Ϲ���
�޾�����˼��������˼����ʲô�ˡ�\n");

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object me)
{
        object ob;

        if(!me->query("mark/louth_huaqiu"))
        {
		if(objectp(present("flower ball",me)))
		{
			command("say �����Ѿ���������");
			return 1;
		}

                command ("say �鷳��һ���£����Ұ����������������ӣ�
��һ����ܸ��˵ġ���л�ˡ�\n");
		ob=new(__DIR__"obj/huaqiu");    
		ob->move(me);
		return 1;
        }

	command ("say �ϴε��¶�л���ˡ�\n");
	return 1;
}
