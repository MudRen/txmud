// paper.c
// Find

inherit ITEM;

protected string content = "[1;37m
         ��ӭ�¾��� - %s

    ��ӭ���������¡����ӣ������¡������ϼ�԰�ڵ�
ַ�ǣ�
           [1;32mhttp://www.mud-fl.com[1;37m
�����Ǿ����Ǿ���Ҫȥתת�ĵط�����ʲô���´��¶�
�������﹫�����������ס����һ��Ҫ��������ȥ����
���������в����ջ�

    ����һ���»������������ܶ����ս��Ҫ��ȥһһ
Ӧ���������ʲô�����õط���������ס�����ʡ�

    ���ڿ�ʼ�ɣ����Լ���˫�֣������õ�������

    ���ţ�[47m[1;31m��[1;35m��[1;32m��[1;33m��[1;36m��[1;34m��[1;37m���ʡ�����
[2;37;0m
";


protected string this_long = "\n��ӭ %s ��ס���£����� read book ����
��ϸ�Ķ���ס�ֲᡣ\n";

protected string query_long()
{
	return this_long;
}

void set_owner(string name)
{
	if(!stringp(name) || !sizeof(name))
		return;

	this_long = sprintf(this_long, name);
	content = sprintf(content, name);
	set("name", sprintf("%s����ס�ֲ�", name));
}

void create()
{
	set_name("��", ({ "book" }) );
	set("unit", "��");
	set("long",(: query_long :));
	set_weight(50);
	setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
	object shi,me = this_player();

	if(arg != "book")
		return notify_fail("��Ҫ��ʲô��\n");

	write(content);

	me->set_temp("read_book",1);

	shi = present("dayuan xianshi",environment(me));
	if(shi)
		shi->can_enter(me);
	return 1;
}
