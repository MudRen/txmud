// guide.c

#include <ansi.h>

inherit NPC;

string *random_name1 = ({
        "灰衣",
        "白衣",
        "黑衣",
        "红袍",
        "蓝袄",
        "懒汉",
        "酒鬼",
        "蓝衣",
        "紫杉",
});

string *random_name2 = ({
        "青年",
        "老人",
        "路人",
        "中年人",
        "王老五",
        "张三",
        "吴老大",
        "赵老六",
        "李四",
});

string *random_id = ({
        "shu sheng",
        "man",
        "lu ren",
        "tiao fu",
        "ku li",
        "da han",
        "xian han",
        "zhuang han",
        "li si",
        "old man",
        "zhang san",
});

//protected string maze="/wiz/aiai/path2/midao";
protected string maze="/d/path2/midao";

string ask_me(object who);

protected void dest_me();

void create()
{
        int i;

        i=random(sizeof(random_name2));
        set_name(HIG+random_name1[random(sizeof(random_name1))]+
                random_name2[i]+NOR, 
                ({ random_id[random(sizeof(random_id))] }) );
                

        set("gender", "男性" );

        set("age", random(30)+20);
        set("str", 20);
        set("cor", 30);
        set("int", 20);
        set("per", 20);
        set("con", 20);
        set("kar", 20);

        set(NO_KILL,1);

        set("long",@LONG
这是一个四处游荡的人，不时的左右张望，看
见你来了，想慌忙的走开。
LONG );

        set("combat_exp", 100000);

        set("chat_chance", 5);
        set("chat_msg", ({
            (: random_move :)
        }) );

        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 60);

        set("inquiry", ([
                "秀秀" : (: ask_me :),
                "xiuxiu" : (: ask_me :),
]) );

        setup();
                carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        if(find_call_out("dest_me") == -1)
                call_out("dest_me",60*6);
}

string ask_me(object who)
{
        object ob=this_object();
    object room,enter,me = this_player();
        object xin;

        if ( who->query("quest/huashan_quest/name")!="飞贼展飞熊的踪迹" ||
                 !who->query("quest/huashan_quest/search") )
                 return 0;

        // 送到秘道中
        room = find_object(maze);
        if(!room)
                room = load_object(maze);
        if(!room)
                return "华山“飞贼”任务出现错误，请向巫师报告。\n";

        if(!objectp(enter = room->init_dilao(me)))
                return "华山“飞贼”任务出现错误，请向巫师报告。\n";

        tell_room(this_object(),me->name()+"跟着"+ob->name()+"一起走了。\n",({me}));
        me->move(enter);

                if ( objectp(xin=present("shouxin", me)) &&
                        xin->query("for_xiuxiu") )
                        destruct(xin);

        write(CYN+ob->name()+"说道：你是二当家派来看秀秀的吧，小的这就给您带路。\n\n"
        +NOR"你跟着"+ob->name()+"来到了一个隐蔽的地方。\n");

        call_out("dest_me", 3);

        return "...";

}

protected void dest_me()
{
        if(environment())
            tell_object(environment(),this_object()->name()+"急急忙忙地离开了。\n");
        destruct(this_object());
}

