// sz_gao.c

inherit ITEM;

protected int mangle = 100;
int is_mine_tool() { return 1; }
int tool_can_use() { return (mangle > 0); }
int no_save_in_home() { return 1; }
string query_long()
{
	if(mangle > 0)
		return "����һ���ھ��õ�ʮ�ָ䡣\n";
	else
		return "����һ�ѻ�����ʮ�ָ䡣\n";
}

void create()
{
	set_name("ʮ�ָ�", ({ "shi zi gao" }) );
	set_weight(2000);
	set("unit", "��");
	set("long", (: query_long :));
	set("value", 500);
}

void use_this_tool()
{
	if( (--mangle <= 0) && environment() )
		tell_object(environment(), "\nʮ�ָ仵�ˡ�\n\n");
	set("value", 0);
}
