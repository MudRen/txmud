/*************
 * ��׼��Ʊ  *
 * by Find.  *
 *************/

inherit ITEM;

class pawn_ob
{
	string master;		// ���� ID
	string pob_file;	// ��Ʒ�ļ���
	int time;		// ����ʱ��
	string hockshop;	// �����ļ���
	string ps_long;		// ��Ʊ����
}

protected class pawn_ob this_one;

string this_long()
{
	if(!this_one || !this_one->ps_long)
		return "����һ�ſհ׵ĵ�Ʊ��\n";
	else
		return this_one->ps_long;
}

void use_this_stamp(mixed *use)
{
	if(!use || !sizeof(use))
		return;

	this_one = new(class pawn_ob);

	this_one->master = use[0];
	this_one->pob_file = use[1];
	this_one->time = use[2];
	this_one->hockshop = use[3];
	if(bufferp(use[4]))
		this_one->ps_long = read_buffer(use[4]);
	else
		this_one->ps_long = use[4];
}

// ��ѯ����
string query_master()
{
	if(!this_one)
		return 0;
	else
		return this_one->master;
}

string query_pob_file()
{
	if(!this_one)
		return 0;
	else
		return this_one->pob_file;
}

int query_rtime()
{
	if(!this_one)
		return 0;

	else
		return this_one->time;
}

string query_hockshop()
{
	if(!this_one)
		return 0;

	else
		return this_one->hockshop;
}

mixed *query_all_msg()
{
	if(!this_one)
		return 0;

	return ({
		this_one->master,
		this_one->pob_file,
		this_one->time,
		this_one->hockshop,
		this_one->ps_long
	});
}

void create()
{
	set_name("��Ʊ", ({ "pawn stamp", "stamp" }));
	set_weight(0);
	set("unit", "��");
	set("long", (: this_long :));
	setup();
}

int is_pawn_stamp() { return 1; }
