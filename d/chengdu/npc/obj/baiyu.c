// baiyu.c

inherit ITEM;

protected string master;

string query_master() { return master; }
void set_master(string id){
	if(!master)
		master = id;
}
void create()
{
	set_name("�ױ�������", ({ "bai yu" }) );
	set_weight(100);
	set("value", 1);
	set("unit", "��");
	set("long", "����һ��Сָ�׸Ǵ����ɫ���ӡ�\n");
}
