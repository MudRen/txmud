// shu_boss.c
// By Find.

#include <ansi.h>

inherit F_DEALER;

static int being_doing = 0;

mixed poem =({
({
		"葡萄美酒夜光杯，",
		"欲弹琵琶马上催。",
		"醉卧沙场君莫笑，",
		"古来征战几人回。",
	}),

({
		"独在异乡为异客，",
		"每逢佳节倍思亲。",
		"遥知兄弟登高处，",
		"遍插茱萸少一人。",
	}),

({
		"昨夜裙带解，",
		"今朝嘻子飞。",
		"铅华不可弃，",
		"莫是藁砧归。",
	}),

({
		"春眠不觉晓，",
		"处处闻啼鸟。",
		"夜来风雨声，",
		"花落知多少。",
	}),

({
		"床前明月光，",
		"疑是地上霜。",
		"举头望明月，",
		"低头思故乡。",
	}),

({
		"生当作人杰，",
		"死亦为鬼雄。",
		"至今思项羽，",
		"不肯过江东。",
	}),

({
		"寥落古行宫，",
		"宫花寂寞红。",
		"白头宫女在，",
		"闲坐说玄宗。",
	}),

({
		"功盖三分国，",
		"名成八阵图。",
		"江流石不转，",
		"遗恨失吞吴。",
	}),

({
		"闺中少妇不知愁，",
		"春日凝妆上翠楼。",
		"忽见陌头杨柳色，",
		"悔教夫婿觅封侯。",
	}),

({
		"昨夜风开露进桃，",
		"未央前殿月轮高。",
		"平阳歌舞新承宠，",
		"帘外春寒赐锦袍。",
	}),

({
		"故园东望路漫漫，",
		"双袖龙钟泪不干。",
		"马上相逢无纸笔，",
		"凭君传语报平安。",
	}),

({
		"隐隐飞桥隔野烟，",
		"石矶西畔问渔船。",
		"桃花尽日随流水，",
		"洞在清溪何处边。",
	}),

({
		"月落乌啼霜满天，",
		"江枫渔火对愁眠。",
		"姑苏城外寒山寺，",
		"夜半钟声到客船。",
	}),

({
		"禁门宫树月痕过，",
		"媚眼惟看宿鹭窠。",
		"斜拔玉钗灯影畔，",
		"剔开红焰救飞蛾。",
	}),

({
		"金陵津渡小山楼，",
		"一宿行人自可愁。",
		"潮落夜江斜月里，",
		"两三星火是瓜州。",
	}),

({
		"日光斜照集灵台，",
		"红树花迎晓露开。",
		"昨夜上皇新授录，",
		"太真含笑入帘来。",
	}),
});

string *head = ({
"张老板轻声吟着：",
"张老板摇头晃脑的吟道：",
"张老板闭目低声叹道：",
});

string *end = ({
"张老板叹道：妙哉斯文！！",
"张老板说道：真乃绝妙好词！",
"张老板摇头晃脑说道：真乃...绝世佳作！！",
"张老板说道：妙！！妙！！",
});

void elocnte_poem();

void create()
{
        set_name("张耀声", ({ "boss zhang", "boss", "zhang" }) );
	set("title","书店老板");
        set("gender", "男性" );
        set("age", 45);
        set("long","汇文阁老板。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		BOOK_DIR"luo_book":5,
		BOOK_DIR"guwen_book":5,
        ]) );

	set("chat_chance", 10);
	set("night_chat_msg", ({
	(: elocnte_poem :),
}));

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
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N冲着$n说道：别影响我做生意，赶紧出去！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"对不起，鄙号已经关门了，"+RANK_D->query_respect(ob)+
			"请明天再来吧。\n"NOR
			: ( (time <= 60) ? CYN"张老板笑眯眯的说道：请您等一下吧，小号马上就开门了。\n"NOR
			: CYN"张老板说道：请天亮了再来吧。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"张老板嘴里咕哝着：书中自有黄金屋。。。颜如玉。。。\n"NOR);
                        break;
                case 1:
                        say( CYN"张老板一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "光临，小号蓬壁生辉，请进，请进。\n"NOR);
                        break;
		}
	}
}

void elocnte_poem()
{
	if(being_doing || is_day())
		return;
	being_doing = 1;
	call_out("doing",1,random(sizeof(poem)),0);
}

void doing(int which,int num)
{
	remove_call_out("doing");
	if(num >= sizeof(poem[which]))
	{
		say(CYN+end[random(sizeof(end))]+"\n\n"+NOR);
		being_doing = 0;
		return;
	}
	say( CYN+head[random(sizeof(head))]+poem[which][num] +"\n"+NOR);
	call_out("doing",1+random(3),which,num+1);
}