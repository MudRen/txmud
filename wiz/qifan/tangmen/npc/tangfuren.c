// tangfuren.c

inherit NPC;

nomask int is_doctor() {return 1;}
protected void do_cure(object, string);

void create()
{
	set("class", "tangmen");

	set_name("�Ʒ���", ({"tang furen"}));
	set("title", "ɢ����Ů");

	set("long", @TEXT
hehe,û�����
TEXT
);

	set(NO_KILL, 1);

	set("gender","Ů��");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

        set("inquiry", ([
//                "����" : (: ask_lian :),
//                "lian" : (: ask_lian :),
//                "���" : (: ask_li :),
//                "pear" : (: ask_li :),
                "�Ƽ̸�": "���м̸ߵ���Ϣ�ˣ������Ҷ��ӣ������뿪��ʮ���ˡ�",
        ]) );

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

// int ask_lian();
// int ask_li();

// int do_lian()
// {
//        object ob = this_player();

//        command("say ����������Ҷ���д�ģ��㿴д�ĺò��á�\n");
//        if(!ob->query_temp("tangmen_temp"))
//                ob->set_temp("tangmen_lutemp", 1);
//        return 1;
// }

// int ask_li()
// {
//        object ob = this_player();

//        if(ob->query_temp("tangmen_temp") >= 1) {
//                command("say �̸�Сʱ���ϲ�����棬��֪��" + RANK_D->query_respect(ob) + "��ϲ���Բ���\n");
//                ob->set_temp("tangmen_temp", 2);
//        }
//        else {
//                command("say �Ҷ�Сʱ���ϲ�����档\n");
//        }
//        return 1;
// }

int do_ask(string arg)
{
        object ob = this_player();

                        if (arg == "���������" || arg == "��������ᡣ" )
 {
                        if (!present("wood pear", ob) && query_temp("wpear_give") < 1) {
                                say("�ѵ���Ҳ֪��������ӡ�����������ҹ�35������ʱ���Ҷ����ҵģ����ڷ��Ŵ������顣���͸���ɡ�\n");
                                new(__DIR__"obj/wpear.c")->move(ob);
                                ob->delete_temp("tangmen_temp");
                                add_temp("wpear_give",1);
                        }
                        else {
                                say("�ѵ���֪��������ӣ���ϧ������û��ʲô���������͸����ˡ�\n");
                        }
                }
                else {
                        command("? " + ob->query("id"));
                        message_vision("�Ʒ����ɻ�ؿ���$N��" + RANK_D->query_respect(ob) + "��˵ʲô�أ�\n", ob);
                }
                return 1;
        }
        return 0;
}