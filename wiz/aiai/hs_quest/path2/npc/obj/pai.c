// pai.c
// by aiai

inherit ITEM;

protected string master;

void set_master(string m)
{
        if(!stringp(m) || (m == "") || master)
                return;

        else
                master = m;
}

string query_master() { return master; }

void create()
{
        set_name("����", ({ "ling pai" }) );
        set_weight(800);

        set("unit","��");
        set("material", "iron");
        set("long", "����һ���ֽ�����ơ�\n");
        setup();
}

