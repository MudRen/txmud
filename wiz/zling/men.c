// by dicky

#include <ansi.h>

inherit NPC;

string ask_for_present();
void create()
{
    set_name("��������", ({ "liwu laoren", "laoren" }) );
	set("title", HIY"����"+HIW" ʹ��"NOR);
	set("gender", "����" );

	set("age", 70);
         
	set("long",
		"�ף��������������ô�����е�����������\n"
                "���������﷢������������������Ҫ��(ask man about ���)\n" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("inquiry", ([
	"���"   : (: ask_for_present :),
        "����"   : (: ask_for_present :),
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
	command("say ������������İɣ�\n");
}

string ask_for_present()
{ 
mapping *holiday= ({

                  ([
                      "name":             HIR"����"+HIC"��һ"NOR,
                      "year":             "2003",
                      "month":            "Mar",
                      "day":              "3",
                  ]),
                  ([
                      "name":             HIR"����"+HIC"����"NOR,
                      "year":             "2003",
                      "month":            "Mar",
                      "day":              "4",
                  ]),
                  ([
                      "name":             HIR"ʥ����"NOR,
                      "year":             "2002",
                      "month":            "Dec",
                      "day":              "24",
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
	write("������:");
	write(month);
	write(" ");
	write(day);
	write(" ");
	write(year);
	write("\n");
	return "�����ֲ���ʲô���գ���Ҫʲô�񰡣�û�ˣ�\n";
	}    
    me = this_player();

    if ((int)me->query("combat_exp") <10000 || (int)me->query("mud_age")<28000)
        return "�ٺ٣����ô�����ƭ�ң�û�ţ���\n";
      
     today = holiday[what_day];   
	if( today["name"] == HIR"ʥ����"NOR)
	{
		check = today["year"] +  today["month"]  +  today["day"] ;
		if(me->query("goodday_gift")==check)
		return "ÿ����һ�ݣ���Ҫ��ô̰�ĺò��ã�\n";
		ob = new (__DIR__"box");
		ob->move(me);
		me->set("goodday_gift",check);
		return "ʥ���ڿ��֣����ϻ�����Űɣ�\n";
	}

     check= "2003gift";    
     if(me->query("goodday_gift")==check)
       return "ÿ����һ�ݣ���Ҫ��ô̰�ĺò��ã�\n";

     ob = new(__DIR__"red");
     ob->move(me);
     me->set("goodday_gift",check);
     return "������" + today["name"]+"����"+HIR"���"NOR+"���Űɣ�\n"+"�������˸�"+me->query("name")+"һ��"+HIR"���"NOR+"��\n";
}

