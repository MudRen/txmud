// xin.c
// by aiai

inherit ITEM;

protected string place;

void set_place(string m)
{
        if(!stringp(m) || (m == "") || place)
                return;

        else
                place = m;
}

string query_place() { return place; }

//长安、左家村、侯集镇和天水镇
string q_long()
{
        return sprintf( "这是一张展飞雄的手信。\n%s",
                        place? sprintf("上面写着：\n\t英弟，大哥近日有大买卖，无暇顾及秀秀，\n她现在被关在%s，你隔些时日去看一下，小心别被人救走了。\n", place):"");
}

void create()
{
        set_name("手信", ({ "shouxin", "xin" }) );
        set_weight(300);

        set("unit","张");
        set("material", "paper");
        set("long", (: q_long :));
        setup();
}

