
// guwen_book.c

inherit ITEM;

void create()
{
        set_name("������־��", ({"guwen book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������־��\n");
                set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 30,
                        "max_skill": 30,
]) );
        }
}