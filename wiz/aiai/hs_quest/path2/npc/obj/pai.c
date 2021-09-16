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
        set_name("令牌", ({ "ling pai" }) );
        set_weight(800);

        set("unit","个");
        set("material", "iron");
        set("long", "这是一个镏金的令牌。\n");
        setup();
}

