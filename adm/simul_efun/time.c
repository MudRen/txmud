// time.c
// ����������ʹ�ò��������̵���,���Ա���.
// by Find.

nomask mixed *localtime( int time )
{
	if( !intp(time) || ( time < 0 ) )
		time = 0;

	return efun::localtime(time);
}

nomask string ctime(int time)
{
	if(!intp(time))
		return "";
	if( time < 0 )
		time = 0;

	return efun::ctime(time);
}

nomask string cctime(int need) /*by Find.*/
{
	string year = "", seg;
	int week,month,y,d,left,h,m,s;
	string *weeks = ({"������","����һ","���ڶ�","������","������","������","������"});
	string *monthes = ({"һ��","����","����",
"����","����","����","����","����",
"����","ʮ��","ʮһ��","ʮ����"});
	mixed *local;

	if(!intp(need))
		return "";
	if( need < 0 )
		need = 0;
	local = localtime(need);

	week = local[6];
	y = local[5];
	month = local[4];
	d = local[3];
	h = local[2];
	m = local[1];
	s = local[0];

	year += chinese_number((int)(y/1000));
	left = y%1000;
	year += chinese_number((int)(left/100));
	left = left%100;
	year += chinese_number((int)(left/10));
	left = left%10;
	year += chinese_number(left);
	year += "��";
        year = replace_string(year,"��","��");

	if(h<6) seg = "�賿";
	else if(h<9) seg = "�糿";
	else if(h<12) seg = "����";
	else if(h<14) seg = "����";
	else if(h<18) seg = "����";
	else seg = "����";

	if(h>12) h -= 12;

	return sprintf("%s%s%s�� %s %s %s��%s��%s��",year,monthes[month],chinese_number(d),
		weeks[week],seg,chinese_number(h),chinese_number(m),chinese_number(s));
}
