// book.c

inherit ITEM;

void create()
{
	string *names = ({
		"���ε���ѡ��", "����躡�", "��̫���硹", "�������ļ���",
		"��˵�ɡ�", "������־��", "�����项", "��٫��իʫ����",
		"����ʿ�д���", "��ˮ��ͼע��"
	});

	set_name( names[random(sizeof(names))], ({ "book" }));
	set_weight(600);
	set("unit", "��");
	set("long", "����ʱ�¶����˳������鼮��\n");
	set("value", 100);

	set("skill", ([
		"name" : "literate",
		"exp_required" : 500,
		"sen_cost" : 30,
		"difficulty" : 30,
		"max_skill" : 40,
	]) );
}