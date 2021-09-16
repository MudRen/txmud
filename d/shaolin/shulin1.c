// Room: /d/shaolin/shulin1.c

inherit ROOM;

#define MAX	100
#define DIS	15

int mu = 100, time = time();
void check_mu();

void create()
{
	set("short", "С����");
	set("long", @LONG
������һƬ������С���֣�����С�����������ϣ���������
���˵����￳����������ʯ�ڣ�Զ��һ������������Լ�ɼ���
LONG
	);

	set("exits",([
	"south" : __DIR__"luanlu5",
	"north" : __DIR__"shulin2",
]));

	setup();
}

void init()
{
	add_action("do_kan","kanchai");
}

int do_kan(string arg)
{
	object me = this_player(),muchai;
/*
	if(!stringp(arg) || arg != "muchai")
		return notify_fail("��Ҫ��ʲô��\n");
*/
	if(!objectp(present("kanchai dao",me)))
		return notify_fail("��û��������ô��ľ��\n");

	if(me->query("kee") < 10)
		return notify_fail("������������֧������Ъһ����ٿ��ɡ�\n");

	check_mu();
	if(!mu)
		return notify_fail("��ƬС�����Ѿ�û��ľ��ɿ��ˡ�\n");
	message_vision("$N��Բ�����еĿ��񵶺ݺݵĿ�����ȥ��\n",me);
	muchai = new(__DIR__"obj/muchai");
	muchai->move(me);
	--mu;
	me->receive_damage("kee",5,"tire");
	me->add_temp("shaolinjob/kanchai",1);
	return 1;
}

void check_mu()
{
	int add;

	if(mu == MAX)
		return;

	add = to_int((time() - time)/DIS);
	if(!add)
		return;
	mu += add;
	if(mu > MAX)
		mu = MAX;
	time = time();
	return;
}