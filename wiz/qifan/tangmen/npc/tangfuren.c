// tangfuren.c

inherit NPC;

nomask int is_doctor() {return 1;}
protected void do_cure(object, string);

void create()
{
	set("class", "tangmen");

	set_name("唐夫人", ({"tang furen"}));
	set("title", "散花天女");

	set("long", @TEXT
hehe,没想好呢
TEXT
);

	set(NO_KILL, 1);

	set("gender","女性");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

        set("inquiry", ([
//                "对联" : (: ask_lian :),
//                "lian" : (: ask_lian :),
//                "梨儿" : (: ask_li :),
//                "pear" : (: ask_li :),
                "唐继高": "你有继高的消息了？他是我儿子，他都离开我十年了。",
        ]) );

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

// int ask_lian();
// int ask_li();

// int do_lian()
// {
//        object ob = this_player();

//        command("say 这个对联是我儿子写的，你看写的好不好。\n");
//        if(!ob->query_temp("tangmen_temp"))
//                ob->set_temp("tangmen_lutemp", 1);
//        return 1;
// }

// int ask_li()
// {
//        object ob = this_player();

//        if(ob->query_temp("tangmen_temp") >= 1) {
//                command("say 继高小时候很喜欢吃梨，不知道" + RANK_D->query_respect(ob) + "你喜欢吃不？\n");
//                ob->set_temp("tangmen_temp", 2);
//        }
//        else {
//                command("say 我儿小时候很喜欢吃梨。\n");
//        }
//        return 1;
// }

int do_ask(string arg)
{
        object ob = this_player();

                        if (arg == "梨儿腹内酸" || arg == "梨儿腹内酸。" )
 {
                        if (!present("wood pear", ob) && query_temp("wpear_give") < 1) {
                                say("难得你也知道这个对子。唉！这个是我过35岁生日时候，我儿送我的，现在放着触景生情。就送给你吧。\n");
                                new(__DIR__"obj/wpear.c")->move(ob);
                                ob->delete_temp("tangmen_temp");
                                add_temp("wpear_give",1);
                        }
                        else {
                                say("难得你知道这个对子，可惜，老身没有什么东西可以送给你了。\n");
                        }
                }
                else {
                        command("? " + ob->query("id"));
                        message_vision("唐夫人疑惑地看着$N：" + RANK_D->query_respect(ob) + "你说什么呢？\n", ob);
                }
                return 1;
        }
        return 0;
}