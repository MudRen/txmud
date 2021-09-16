// oldwoman.c 林芝村藏族老大妈
inherit NPC;
void create()
{
        set_name("藏族大妈", ({ "old woman", "woman" }) );
        set("gender", "女性" );
        set("age", 63);
        set("long", "一个年老色衰的老大娘，动作还是满利落的。\n");
        set("combat_exp", 1500);
        set("env/wimpy", 80);
        set("str", 13);
        set("attitude", "friendly");
        set("inquiry", ([
                "鸡" : "我那老母鸡啊...一定是那几个不务正业的小流氓干的。",
                "流氓" : "那几个小流氓正天不务正业，就在小胡同里喝酒赌钱。"
        ]) );
        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
                "藏族大妈伤心的说道：那个天杀的，偷了我的老母鸡。\n",
                "藏族大妈叹了口气，说道：这是个什麽世道啊。\n",
                "藏族大妈呆呆的望着鸡笼，发起愣来了。\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 100);
}
