// by dicky

#include <ansi.h>

inherit NPC;

string ask_for_present();
void create()
{
    set_name("礼物老人", ({ "liwu laoren", "laoren","man"}) );
	set("title", HIY"礼物使者"NOR);
	set("gender", "男性" );

	set("age", 70);
         
	set("long",
		"咦？这个礼物老人怎么长得有点像启帆啊？\n"
                "他正在那里发红包，看来你可以向他要。(ask man about 红包)\n" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("inquiry", ([
	"红包"   : (: ask_for_present :),
        "礼物"   : (: ask_for_present :),
        "present"   : (: ask_for_present :),
        "gift"   : (: ask_for_present :),
	]) );

	set(NO_KILL, 1);


	setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	command("say 你是来拿礼物的吧？\n");
}

string ask_for_present()
{ 
mapping *holiday= ({

                  ([
                      "name":             HIR"大年"+HIC"初一"NOR,
                      "year":             "2003",
                      "month":            "Feb",
                      "day":              "1",
                  ]),
                  ([
                      "name":             HIR"大年"+HIC"初二"NOR,
                      "year":             "2003",
                      "month":            "Feb",
                      "day":              "2",
                  ]),
                  ([
                      "name":             HIR"圣诞节"NOR,
                      "year":             "2002",
                      "month":            "Dec",
                      "day":              "25",
                  ]),
                  });
    object me,ob;
    mapping today;
    int i,what_day=100;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
    if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);

    for(i=0;i<sizeof(holiday);i++)
      {  today = holiday[i];
	if( month==today["month"]&&day==today["day"])
               what_day=i;
	else if(month==today["month"]&&day==today["day"])
               what_day=i;
      }
	if(what_day==100)
	{
	write("现在是:");
	write(month);
	write(" ");
	write(day);
	write(" ");
	write(year);
	write("\n");
	return "今天又不是什么节日，还要什么礼啊？没了！\n";
	}    
    me = this_player();

    if ((int)me->query("combat_exp") < 10000)
        return "嘿嘿，想用大米来骗我，没门！。\n";
      
     today = holiday[what_day];   
	if( today["name"] == HIR"圣诞节"NOR)
	{
		check = today["year"] +  today["month"]  +  today["day"] ;
		if(me->query("goodday_gift")==check)
		return "每个人一份，不要这么贪心好不好！\n";
		ob = new (__DIR__"box");
		ob->move(me);
		me->set("goodday_gift",check);
		return "圣诞节快乐！这个匣子收着吧！\n";
	}

     check= "2003gift";    
     if(me->query("goodday_gift")==check)
       return "每个人一份，不要这么贪心好不好！\n";

     ob = new(__DIR__"red");
     ob->move(me);
     me->set("goodday_gift",check);
     return "今天是" + today["name"]+"啊！"+HIR"红包"NOR+"收着吧！\n"+"礼物老人给"+me->query("name")+"一个"+HIR"红包"NOR+"。\n";
}

