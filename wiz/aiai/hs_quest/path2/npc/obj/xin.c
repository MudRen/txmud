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

//��������Ҵ塢������ˮ��
string q_long()
{
        return sprintf( "����һ��չ���۵����š�\n%s",
                        place? sprintf("����д�ţ�\n\tӢ�ܣ��������д���������Ͼ�˼����㣬\n�����ڱ�����%s�����Щʱ��ȥ��һ�£�С�ı��˾����ˡ�\n", place):"");
}

void create()
{
        set_name("����", ({ "shouxin", "xin" }) );
        set_weight(300);

        set("unit","��");
        set("material", "paper");
        set("long", (: q_long :));
        setup();
}

