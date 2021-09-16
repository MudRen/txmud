// Room: taolin.c
// ÿ�괺�������Ž����ÿ�ν�� 3 ����

inherit ROOM;
inherit F_SAVE;

static int sum_per_season = 3;

int sum,year,season;

string query_save_file() { return __DIR__"taolin"; }
int do_pick(string arg);
private void init_sum()
{
	int y = query_year(), s = query_season();

	if(!year || (year != y) || !season || (season != s))
	{
		sum = sum_per_season;
		year = y; season = s;
	}
	if(sum < 0)
		sum = 0;
}

int clean_up() { init_sum(); return ::clean_up(); }

void create()
{
	set("short","��ɽ����");
	set("long",@LONG
����һƬ��С��Ұɽ���֣���˵���������һ���ļ����Ὺ
�������Ҳ�ǻ�ɽ��һ���澰��ÿ�괺���������������ʱ��
����������ժ����˵�����������ȥ����̵��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"east": __DIR__"guangw1",
	"west": __DIR__"diaoyuchi",
	"northwest":__DIR__"xiaolu1",

]));

	set("outdoors", "huashan_zx");
	setup();
	restore();
	init_sum();
}

void init()
{
	add_action( (:do_pick:),({"zhai","pick"}));
}

int do_pick(string arg)
{
	object tao;

	if(!stringp(arg) || (arg != "ɽ��" && arg != "����"))
		return notify_fail("��Ҫ��ժʲô��\n");

	if(!(query_season()%2))
		return notify_fail("����һ������Ҳû�С�\n");

	if(sum <= 0)
		return notify_fail("���ϵ������Ѿ���ժ���ˡ�\n");

	if(!objectp(tao = new(__DIR__"obj/tao")))
		return notify_fail("���ϵ������Ѿ���ժ���ˡ�\n");

	--sum;
	message_vision("$N������ժ����һ��$n��\n",this_player(),tao);

	if(!tao->move(this_player()))
		tao->move(this_object());
	save();
	return 1;
}
