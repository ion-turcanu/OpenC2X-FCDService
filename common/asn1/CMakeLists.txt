set(asn1_SRCS
	DENM.c	
	DecentralizedEnvironmentalNotificationMessage.c	
	ManagementContainer.c	
	SituationContainer.c	
	LocationContainer.c	
	ImpactReductionContainer.c	
	RoadWorksContainerExtended.c	
	StationaryVehicleContainer.c	
	AlacarteContainer.c	
	Termination.c	
	ReferenceDenms.c	
	CAM.c	
	CoopAwareness.c	
	CamParameters.c	
	HighFrequencyContainer.c	
	LowFrequencyContainer.c	
	SpecialVehicleContainer.c	
	BasicContainer.c	
	BasicVehicleContainerHighFrequency.c	
	BasicVehicleContainerLowFrequency.c	
	PublicTransportContainer.c	
	SpecialTransportContainer.c	
	DangerousGoodsContainer.c	
	RoadWorksContainerBasic.c	
	RescueContainer.c	
	EmergencyContainer.c	
	SafetyCarContainer.c	
	RSUContainerHighFrequency.c	
	GenerationDeltaTime.c	
	ItsPduHeader.c	
	StationID.c	
	ReferencePosition.c	
	DeltaReferencePosition.c	
	Longitude.c	
	Latitude.c	
	Altitude.c	
	AltitudeValue.c	
	AltitudeConfidence.c	
	DeltaLongitude.c	
	DeltaLatitude.c	
	DeltaAltitude.c	
	PosConfidenceEllipse.c	
	PathPoint.c	
	PathDeltaTime.c	
	PtActivation.c	
	PtActivationType.c	
	PtActivationData.c	
	AccelerationControl.c	
	SemiAxisLength.c	
	CauseCode.c	
	CauseCodeType.c	
	SubCauseCodeType.c	
	TrafficConditionSubCauseCode.c	
	AccidentSubCauseCode.c	
	RoadworksSubCauseCode.c	
	HumanPresenceOnTheRoadSubCauseCode.c	
	WrongWayDrivingSubCauseCode.c	
	AdverseWeatherCondition-ExtremeWeatherConditionSubCauseCode.c	
	AdverseWeatherCondition-AdhesionSubCauseCode.c	
	AdverseWeatherCondition-VisibilitySubCauseCode.c	
	AdverseWeatherCondition-PrecipitationSubCauseCode.c	
	SlowVehicleSubCauseCode.c	
	StationaryVehicleSubCauseCode.c	
	HumanProblemSubCauseCode.c	
	EmergencyVehicleApproachingSubCauseCode.c	
	HazardousLocation-DangerousCurveSubCauseCode.c	
	HazardousLocation-SurfaceConditionSubCauseCode.c	
	HazardousLocation-ObstacleOnTheRoadSubCauseCode.c	
	HazardousLocation-AnimalOnTheRoadSubCauseCode.c	
	CollisionRiskSubCauseCode.c	
	SignalViolationSubCauseCode.c	
	RescueAndRecoveryWorkInProgressSubCauseCode.c	
	DangerousEndOfQueueSubCauseCode.c	
	DangerousSituationSubCauseCode.c	
	VehicleBreakdownSubCauseCode.c	
	PostCrashSubCauseCode.c	
	Curvature.c	
	CurvatureValue.c	
	CurvatureConfidence.c	
	CurvatureCalculationMode.c	
	Heading.c	
	HeadingValue.c	
	HeadingConfidence.c	
	LanePosition.c	
	ClosedLanes.c	
	HardShoulderStatus.c	
	DrivingLaneStatus.c	
	PerformanceClass.c	
	SpeedValue.c	
	SpeedConfidence.c	
	VehicleMass.c	
	Speed.c	
	DriveDirection.c	
	EmbarkationStatus.c	
	LongitudinalAcceleration.c	
	LongitudinalAccelerationValue.c	
	AccelerationConfidence.c	
	LateralAcceleration.c	
	LateralAccelerationValue.c	
	VerticalAcceleration.c	
	VerticalAccelerationValue.c	
	StationType.c	
	ExteriorLights.c	
	DangerousGoodsBasic.c	
	DangerousGoodsExtended.c	
	SpecialTransportType.c	
	LightBarSirenInUse.c	
	HeightLonCarr.c	
	PosLonCarr.c	
	PosPillar.c	
	PosCentMass.c	
	RequestResponseIndication.c	
	SpeedLimit.c	
	StationarySince.c	
	Temperature.c	
	TrafficRule.c	
	WheelBaseVehicle.c	
	TurningRadius.c	
	PosFrontAx.c	
	PositionOfOccupants.c	
	PositioningSolutionType.c	
	VehicleIdentification.c	
	WMInumber.c	
	VDS.c	
	EnergyStorageType.c	
	VehicleLength.c	
	VehicleLengthValue.c	
	VehicleLengthConfidenceIndication.c	
	VehicleWidth.c	
	PathHistory.c	
	EmergencyPriority.c	
	InformationQuality.c	
	RoadType.c	
	SteeringWheelAngle.c	
	SteeringWheelAngleValue.c	
	SteeringWheelAngleConfidence.c	
	TimestampIts.c	
	VehicleRole.c	
	YawRate.c	
	YawRateValue.c	
	YawRateConfidence.c	
	ProtectedZoneType.c	
	RelevanceDistance.c	
	RelevanceTrafficDirection.c	
	TransmissionInterval.c	
	ValidityDuration.c	
	ActionID.c	
	ItineraryPath.c	
	ProtectedCommunicationZone.c	
	Traces.c	
	NumberOfOccupants.c	
	SequenceNumber.c	
	PositionOfPillars.c	
	RestrictedTypes.c	
	EventHistory.c	
	EventPoint.c	
	ProtectedCommunicationZonesRSU.c	
	CenDsrcTollingZone.c	
	ProtectedZoneRadius.c	
	ProtectedZoneID.c	
	CenDsrcTollingZoneID.c
	FCDREQ.c
	FCDBasicHeader.c
	FCDRequestHeader.c
	RequestID.c
	Payload.c
)

set(asn1_support_SRCS
	ANY.c
	asn_codecs_prim.c
	asn_SEQUENCE_OF.c
	asn_SET_OF.c
	ber_decoder.c
	ber_tlv_length.c
	ber_tlv_tag.c
	BIT_STRING.c
	BMPString.c
	BOOLEAN.c
	constraints.c
	constr_CHOICE.c
	constr_SEQUENCE.c
	constr_SEQUENCE_OF.c
	constr_SET.c
	constr_SET_OF.c
	constr_TYPE.c
	der_encoder.c
	ENUMERATED.c
	GeneralizedTime.c
	GeneralString.c
	GraphicString.c
	IA5String.c
	INTEGER.c
	ISO646String.c
	NativeEnumerated.c
	NativeInteger.c
	NativeReal.c
	NULL.c
	NumericString.c
	ObjectDescriptor.c
	OBJECT_IDENTIFIER.c
	OCTET_STRING.c
	per_decoder.c
	per_encoder.c
	per_opentype.c
	per_support.c
	PrintableString.c
	REAL.c
	RELATIVE-OID.c
	T61String.c
	TeletexString.c
	UniversalString.c
	UTCTime.c
	UTF8String.c
	VideotexString.c
	VisibleString.c
	xer_decoder.c
	xer_encoder.c
	xer_support.c
)

#link_directories(${ASN1C_EXECUTABLE})

add_library(asn SHARED ${asn1_SRCS} ${asn1_support_SRCS})

install(TARGETS asn DESTINATION lib)

