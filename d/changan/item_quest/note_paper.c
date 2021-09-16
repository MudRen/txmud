// note_paper.c : item quest note paper
#include <ansi.h>

inherit ITEM;

int do_look(string str);
string time_period(int timep, object me);

void create()
{
    set_name("小纸条",({ "note paper", "paper" }) );
        set_weight(100);
    if ( clonep() )
                set_default_object(__FILE__);
    else 
        {
                set("unit", "张");
        set("material", "paper");
        set("long", "这是一张空白的小纸条。\n");
                set("end_time", 0);
        }
}

void init()
{
        add_action("do_look", "look");
}

int do_look(string str)
{
        string msg;
        object ob;

        if (!str) return 0;

        if (str) str = lower_case(str);

        if (str!="paper" && str!="zhi" && str!="note paper" && str!="np") return 0;

        ob=this_object();

        msg=ob->query("long");

        if (!ob->query("owner")) 
        {
                tell_object(this_player(), msg);
                return 1;
        }

        if (ob->query("owner")!=this_player()->name() ||
                ob->query("owner_id")!=this_player()->query("id") )
        {
                msg=replace_string(msg, "temp_owner", ob->query("owner"));
                if (this_player()->query_cor()>25)
                        msg+="你心想：好像是大买卖啊，俺抢在前头做也许能赚一笔耶！\n";
                else
                        msg+="你心想：这是别人的买卖，我还是不要插手了。\n";
                tell_object(this_player(), msg);
                return 1;
        }
        else    
                msg=replace_string(msg, "temp_owner", "你");

        if (time() < (int)ob->query("end_time",1))
                msg+="你估计了一下，大概还有"
                        + time_period((int)ob->query("end_time",1)-time(), ob) + "来完成。\n";
        else
                msg+="你看了下时辰，估计这次买卖要吹了。\n";

        tell_object(this_player(), msg);

        return 1;
}

string time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        //tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n请在" + time + "内");
                //sysmsg = "在" + time + "内";
        return time;
}
