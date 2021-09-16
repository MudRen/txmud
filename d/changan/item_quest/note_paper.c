// note_paper.c : item quest note paper
#include <ansi.h>

inherit ITEM;

int do_look(string str);
string time_period(int timep, object me);

void create()
{
    set_name("Сֽ��",({ "note paper", "paper" }) );
        set_weight(100);
    if ( clonep() )
                set_default_object(__FILE__);
    else 
        {
                set("unit", "��");
        set("material", "paper");
        set("long", "����һ�ſհ׵�Сֽ����\n");
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
                        msg+="�����룺�����Ǵ���������������ǰͷ��Ҳ����׬һ��Ү��\n";
                else
                        msg+="�����룺���Ǳ��˵��������һ��ǲ�Ҫ�����ˡ�\n";
                tell_object(this_player(), msg);
                return 1;
        }
        else    
                msg=replace_string(msg, "temp_owner", "��");

        if (time() < (int)ob->query("end_time",1))
                msg+="�������һ�£���Ż���"
                        + time_period((int)ob->query("end_time",1)-time(), ob) + "����ɡ�\n";
        else
                msg+="�㿴����ʱ���������������Ҫ���ˡ�\n";

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

        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        //tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n����" + time + "��");
                //sysmsg = "��" + time + "��";
        return time;
}
